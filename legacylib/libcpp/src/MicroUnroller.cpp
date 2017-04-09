#include "MicroUnroller.hpp"
#include "smt.hpp"
#include "abstraction.hpp"
#include "ast.hpp"
#include "rewriter.hpp"
#include "logging.hpp"
#include <sstream>

using namespace std;

namespace ila
{


    void MicroUnroller::addInputNodes()
    {
    // assume all uabs's input has a parent
        Z3ExprAdapter z3expr(*m_pContext, "");
        z3expr.setNameSuffix( frame2suffix(-1,true)  );

        for (auto i : m_pAbstraction->getInps()) {
            z3::expr pi = z3expr.getExpr(i.second.var.get());
            unsigned idx = addPrimaryInput(pi); // yes, we do it, but we don't use it
            m_mInputIndices[ i.second.var.get() ] = idx;
        }
        for (auto inp : m_pUAbstraction->getInps() ) {
            ILA_ASSERT(inp.second.parent, "Cannot translate micro-inst with standalone input to the SMT template.");
        }

    }

    void MicroUnroller::_initVar(Z3ExprAdapter& z3expr, const npair_t& p, bool allowInit)
    {
        unsigned nFrame = frame();
        Node* var = p.var.get();
        Node* init = p.init.get();

        // var_  : aes_state_
        if(!allowInit || var->equal(init))
        {
            z3::expr c = z3expr.getExpr(var).simplify();
            unsigned idx = addOutput(c);
            m_mStateIndices[p.var.get()] = idx;
            log2("Unroller")<<"ADD "<<c<<" to "<<nFrame<<","<<idx<<std::endl;
        }
        else
        {
            z3::expr c = z3expr.getExpr(init).simplify();
            unsigned idx = addOutput(c);
            m_mStateIndices[p.var.get()] = idx;
            log2("Unroller")<<"ADD "<<c<<" to "<<nFrame<<","<<idx<<std::endl;
        }
        

        if ((bool) p.ipred) {
            z3::expr p1 = z3expr.getExpr(p.ipred.get()).simplify();
            addAssump(p1);
        }
    }

    void MicroUnroller::addArchStatesToFirstFrame()
    {
        ILA_ASSERT(frame()==0,"Unexpected frame number!");
        log2("Unroller")<<"(D!) ADD arch state to frame 0"<<std::endl;
        Z3ExprAdapter z3expr(*m_pContext, "");
        z3expr.setNameSuffix( frame2suffix(-1,true)  );

        for (auto b : m_pUAbstraction->getBits())
            if(b.second.parent != NULL) 
                _initVar(z3expr, b.second,false); 
        for (auto r : m_pUAbstraction->getRegs())
            if(r.second.parent != NULL) 
                _initVar(z3expr, r.second,false); 
        for (auto r : m_pUAbstraction->getMems())
            if(r.second.parent != NULL) 
                _initVar(z3expr, r.second,false); 

        log2("Unroller")<<"(Done) ADD arch state to frame 0"<<std::endl;
    }

    void MicroUnroller::addAllStatesToSecondFrame(bool initCondSet)
    {
        ILA_ASSERT(frame()==1,"Unexpected frame number!");
        log2("Unroller")<<"(D!) ADD ALL state to frame "<<frame()<<std::endl;
        Z3ExprAdapter z3expr(*m_pContext, "");
        Z3ExprAdapter z3expr_micro(*m_pContext, ""); 
        z3expr.setNameSuffix( frame2suffix(frame()-1,false)  );
        z3expr_micro.setNameSuffix( "_in_" + m_pAbstraction->getName()  + "_" + m_pUAbstraction->getName() );

        //no need for substitution ? 
        for (auto b : m_pUAbstraction->getBits() )
            if(b.second.parent)
            {
                //try to find it's next expr in m_pAbstaction
                Node * parentNext = b.second.parent->next.get();
                z3::expr c = z3expr.getExpr(parentNext);
                unsigned idx = addOutput(c);
                m_mStateIndices[b.second.var.get()] = idx;
                log2("Unroller")<<"ADD "<<c<<" to "<<frame()<<","<<idx<<std::endl;
            }
            else
            {
                if (b.second.var.get()->equal(b.second.init.get()) || ! initCondSet )
                    _initVar(z3expr_micro, b.second,initCondSet);
                else
                    _initVar(z3expr, b.second,initCondSet);
            }
        for (auto r : m_pUAbstraction->getRegs() )
            if(r.second.parent)
            {
                //try to find it's next expr in m_pAbstaction
                Node * parentNext = r.second.parent->next.get();
                z3::expr c = z3expr.getExpr(parentNext);
                unsigned idx = addOutput(c);
                m_mStateIndices[r.second.var.get()] = idx;
                log2("Unroller")<<"ADD "<<c<<" to "<<frame()<<","<<idx<<std::endl;
            }
            else
            {
                if (r.second.var.get()->equal(r.second.init.get()) || ! initCondSet )
                    _initVar(z3expr_micro, r.second,initCondSet);
                else
                    _initVar(z3expr, r.second,initCondSet);
            }
        for (auto m : m_pUAbstraction->getMems() )
            if(m.second.parent)
            {
                //try to find it's next expr in m_pAbstaction
                Node * parentNext = m.second.parent->next.get();
                z3::expr c = z3expr.getExpr(parentNext);
                unsigned idx = addOutput(c);
                m_mStateIndices[m.second.var.get()] = idx;
                log2("Unroller")<<"ADD "<<c<<" to "<<frame()<<","<<idx<<std::endl;
            }
            else
            {
                if (m.second.var.get()->equal(m.second.init.get()) || ! initCondSet )
                    _initVar(z3expr_micro, m.second,initCondSet);
                else
                    _initVar(z3expr, m.second,initCondSet);
            }

        log2("Unroller")<<"(Done) ADD ALL state to frame "<<frame()<<std::endl;
    }

    void MicroUnroller::addAllStatesToLaterFrame()
    {
        ILA_ASSERT(frame()>=2,"Unexpected frame number!");
        log2("Unroller")<<"(D!) ADD ALL state to frame "<<frame()<<std::endl;
        unsigned nFrame = frame();
        Z3ExprAdapter z3expr(*m_pContext, "");
        z3expr.setNameSuffix( frame2suffix(frame()-1,false)  );

        // Now we need to substitute
        // collect all possible states we may encounter
        z3::expr_vector sub_src(*m_pContext);
        z3::expr_vector sub_dst(*m_pContext);

        // no need worry about inputs, they are just there
        unsigned i=0;
        for (auto b : m_pUAbstraction->getBits() )  {
            sub_src.push_back(z3expr.getExpr(b.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame-1][i++]);
        }
        for (auto r : m_pUAbstraction->getRegs() )  {
            sub_src.push_back(z3expr.getExpr(r.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame-1][i++]);
        }
        for (auto m : m_pUAbstraction->getMems() )  {
            sub_src.push_back(z3expr.getExpr(m.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame-1][i++]);
        }
        // now we have all of that
        // let's dump it
        if(debug)  {
            ILA_ASSERT(sub_src.size()==sub_dst.size(),"unbalanced size");
            log2("Unroller")<<"(DEBUG) will replace:"<<std::endl;
            for (unsigned i=0;i<sub_src.size();i++)
                    log2("Unroller")<<sub_src[i] <<" -> " <<sub_dst[i] <<std::endl;
        }

        Node * nodeValid = m_pUAbstraction->getFetchValidNode().get();
        z3::expr valid = z3expr.getExpr(nodeValid);
        // now let's place it 
        for (auto b : m_pUAbstraction->getBits()) {
            if( b.second.next.get() )  {
                z3::expr eu = z3expr.getExpr(b.second.next.get()); // micro arch will update that
                z3::expr ea = z3expr.getExpr(b.second.var.get());
                z3::expr next = z3::ite(valid,eu,ea);
                unsigned idx = addOutput( next.substitute(sub_src, sub_dst).simplify() );
                ILA_ASSERT(idx == m_mStateIndices[b.second.var.get()] , "Put to a wrong place in the frame" ); 
            }
            else
            {
                z3::expr e = z3expr.getExpr(b.second.var.get()); // its next expression is itself
                unsigned idx = addOutput( e.substitute(sub_src, sub_dst).simplify() );
                ILA_ASSERT(idx == m_mStateIndices[b.second.var.get()] , "Put to a wrong place in the frame" ); 
            }
        }

        for (auto r : m_pUAbstraction->getRegs()) {
            if( r.second.next.get() )  {
                z3::expr eu = z3expr.getExpr(r.second.next.get()); // micro arch will update that
                z3::expr ea = z3expr.getExpr(r.second.var.get());
                z3::expr next = z3::ite(valid,eu,ea);
                unsigned idx = addOutput( next.substitute(sub_src, sub_dst).simplify() );
                ILA_ASSERT(idx == m_mStateIndices[r.second.var.get()] , "Put to a wrong place in the frame" ); 
            }
            else   {
                z3::expr e = z3expr.getExpr(r.second.var.get()); // its next expression is itself
                unsigned idx = addOutput( e.substitute(sub_src, sub_dst).simplify() );
                ILA_ASSERT(idx == m_mStateIndices[r.second.var.get()] , "Put to a wrong place in the frame" ); 
            }
        }

        for (auto m : m_pUAbstraction->getMems()) {
            if( m.second.next.get() ) {
                z3::expr eu = z3expr.getExpr(m.second.next.get()); // micro arch will update that
                z3::expr ea = z3expr.getExpr(m.second.var.get());
                z3::expr next = z3::ite(valid,eu,ea);
                unsigned idx = addOutput( next.substitute(sub_src, sub_dst).simplify() );
                ILA_ASSERT(idx == m_mStateIndices[m.second.var.get()] , "Put to a wrong place in the frame" ); 
            }
            else   {
                z3::expr e = z3expr.getExpr(m.second.var.get()); // its next expression is itself
                unsigned idx = addOutput( e.substitute(sub_src, sub_dst).simplify() );
                ILA_ASSERT(idx == m_mStateIndices[m.second.var.get()] , "Put to a wrong place in the frame" ); 
            }
        }        

        log2("Unroller")<<"(Done) ADD arch state to frame 0"<<std::endl;
    }

    z3::expr MicroUnroller::subsFormula(Node * n)
    {
        Z3ExprAdapter z3expr(*m_pContext, "");
        unsigned nFrame = frame();
        z3expr.setNameSuffix( frame2suffix(frame()-1,false)  );

        z3::expr_vector sub_src(*m_pContext);
        z3::expr_vector sub_dst(*m_pContext);

        unsigned i=0;
        for (auto b : m_pUAbstraction->getBits() )  {
            sub_src.push_back(z3expr.getExpr(b.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame][i++]);
        }
        for (auto r : m_pUAbstraction->getRegs() )  {
            sub_src.push_back(z3expr.getExpr(r.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame][i++]);
        }
        for (auto m : m_pUAbstraction->getMems() )  {
            sub_src.push_back(z3expr.getExpr(m.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame][i++]);
        }
        // now we have all of that
        // let's dump it
        if(debug)  {
            ILA_ASSERT(sub_src.size()==sub_dst.size(),"unbalanced size");
            log2("Unroller")<<"(DEBUG) will replace:"<<std::endl;
            for (unsigned i=0;i<sub_src.size();i++)
                    log2("Unroller")<<sub_src[i] <<" -> " <<sub_dst[i] <<std::endl;
        }

        z3::expr assumptExpr = z3expr.getExpr( n );
        log2("Unroller")<<"Assumption before sub: "<<assumptExpr<<std::endl;
        z3::expr assumptExprSub = assumptExpr.substitute(sub_src,sub_dst);
        log2("Unroller")<<"Assumption after sub: "<<assumptExprSub<<std::endl;
        return assumptExprSub;
    }

    void MicroUnroller::addAssumption(NodeRef * assumption)
    {
        if( ! assumption->node->type.isBool() )
            throw PyILAException(PyExc_TypeError, "Assumption must be Boolean.");

        auto tmpAssumption = subsFormula( assumption->node.get() );
        addAssump( tmpAssumption );
    }

    void MicroUnroller::dumpAssertion(NodeRef * assertion, const std::string & fileName)
    {

        if( ! assertion->node->type.isBool() )
            throw PyILAException(PyExc_TypeError, "Assertion must be Boolean.");

        z3::expr assertExprSub = subsFormula( assertion->node.get() );

        m_pSolver->reset();
        //m_pSolver->push();

        for(z3::expr & e: m_Assumps ) {
            m_pSolver->add(e);
        }

        if( m_pSolver->check() != z3::sat ) {
            std::cerr<<"Assumptions do not hold, unable to check assertion."<<std::endl;
            m_pSolver->reset();
            //m_pSolver->pop();
            return ; // or true ?
        }
        m_pSolver->add(!assertExprSub);

        ofstream smtFile(fileName);
        smtFile<<(*m_pSolver)<<std::endl;

        
        m_pSolver->reset();
        //m_pSolver->pop();

    }

    bool MicroUnroller::checkAssertion(NodeRef * assertion)
    {
        if( ! assertion->node->type.isBool() )
            throw PyILAException(PyExc_TypeError, "Assertion must be Boolean.");

        z3::expr assertExprSub = subsFormula( assertion->node.get() );

        m_pSolver->reset();
        //m_pSolver->push();

        for(z3::expr & e: m_Assumps ) {
            m_pSolver->add(e);
        }

        if( m_pSolver->check() != z3::sat ) {
            std::cerr<<"Assumptions do not hold, unable to check assertion."<<std::endl;
            return false; // or true ?
        }
        m_pSolver->add(!assertExprSub);

        auto r = m_pSolver->check();
        if(r == z3::unsat) {
            //m_pSolver->pop();
            m_pSolver->reset();
            std::cerr<<"Assertion is valid!"<<std::endl;
            return true; // here we prove it
        }
        else {
            z3::model m = m_pSolver->get_model();
            std::cerr <<"Assertion is not valid because of the cex:\n" << m << std::endl;
            std::ofstream cexf("cex.out");
            EvalEachFrame(m,this,cexf);
            std::cerr<<"CounterExample has been dumped to cex.out"<<std::endl;
            //m_pSolver->pop();
            
            m_pSolver->reset();
            return false;
        }

    }

    std::string MicroUnroller::frame2suffix(unsigned fr, bool init)
    {
        if(init)
            return "_" ;
        return "_" + boost::lexical_cast<string>(fr) + "_" ;
    }

    void MicroUnroller::setup2Frames(bool initCond)
    {
        addInputNodes();
        addArchStatesToFirstFrame();
        debugFrame();
        newFrame();
        addAllStatesToSecondFrame(initCond);
        debugFrame();
    }
    void MicroUnroller::unrollToStep(unsigned bound)
    {
        while(frame()<bound)
        {
            debugFrame();
            newFrame();
            addAllStatesToLaterFrame();
        }
    }
    void MicroUnroller::InsertAssumptions()
    {
        for (z3::expr & a : m_Assumps)
            m_pSolver->add(a);
    }

    void MicroUnroller::InsertAssumptSub(z3::expr_vector &src, z3::expr_vector &dest)
    {
        for (z3::expr & a : m_Assumps) {
            log2("Unroller")<<"Insert assumpt sub before:"<<a<<std::endl;
            log2("Unroller")<<"Insert assumpt sub after:"<<a.substitute(src,dest)<<std::endl;
            m_pSolver->add(a.substitute(src,dest));
        }
    }

    z3::expr MicroUnroller::subsFormulaOnFrame(unsigned nframe, nptr_t & formula)
    {
        Z3ExprAdapter z3expr(*m_pContext, "");
        z3expr.setNameSuffix( frame2suffix(frame()-1,false)  );

        z3::expr_vector sub_src(*m_pContext);
        z3::expr_vector sub_dst(*m_pContext);

        unsigned i=0;
        for (auto b : m_pUAbstraction->getBits() )  {
            sub_src.push_back(z3expr.getExpr(b.second.var.get()));
            sub_dst.push_back(m_vOutputs[nframe][i++]);
        }
        for (auto r : m_pUAbstraction->getRegs() )  {
            sub_src.push_back(z3expr.getExpr(r.second.var.get()));
            sub_dst.push_back(m_vOutputs[nframe][i++]);
        }
        for (auto m : m_pUAbstraction->getMems() )  {
            sub_src.push_back(z3expr.getExpr(m.second.var.get()));
            sub_dst.push_back(m_vOutputs[nframe][i++]);
        }
        // now we have all of that
        // let's dump it
        if(debug)  {
            ILA_ASSERT(sub_src.size()==sub_dst.size(),"unbalanced size");
            log2("Unroller")<<"(DEBUG) will replace:"<<std::endl;
            for (unsigned i=0;i<sub_src.size();i++)
                    log2("Unroller")<<sub_src[i] <<" -> " <<sub_dst[i] <<std::endl;
        }

        z3::expr assumptExpr = z3expr.getExpr( formula.get() );
        log2("Unroller")<<"Assumption before sub: "<<assumptExpr<<std::endl;
        z3::expr assumptExprSub = assumptExpr.substitute(sub_src,sub_dst);
        log2("Unroller")<<"Assumption after sub: "<<assumptExprSub<<std::endl;
        return assumptExprSub;
    }

    z3::expr MicroUnroller::getNodeOnFrame(unsigned nframe, nptr_t & node)
    {
        return getOutput( nframe, node.get() );
    }

    z3::context MicroUnroller::MicroUnrollContext;
    z3::solver  MicroUnroller::MicroUnrollSolver(MicroUnroller::MicroUnrollContext);

    MicroUnroller *  MicroUnroller::NewUnroller(AbstractionWrapper *Abs, AbstractionWrapper *Uabs, bool InitCond)
    {
        return new MicroUnroller("", *(Abs->abs.get()), *(Uabs->abs.get()), MicroUnrollContext, MicroUnrollSolver, InitCond);
    }
    
    void MicroUnroller::EqOffline(const std::string & fileName, MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2)
    {
        // first let's look it up in the two 
        npair_t & np1 = m1->m_pUAbstraction->findInMap(n1)->second;
        npair_t & np2 = m2->m_pUAbstraction->findInMap(n2)->second;

        z3::expr e1 = m1->getNodeOnFrame(m1->frame(), np1.var);
        z3::expr e2 = m2->getNodeOnFrame(m2->frame(), np2.var);

        z3::expr mitre = (e1 != e2).simplify();

        MicroUnrollSolver.reset();
        //MicroUnrollSolver.push();
        m1->InsertAssumptions();
        m2->InsertAssumptions();

        if(MicroUnrollSolver.check() == z3::unsat) {
            std::cerr<<"Assumptions do not hold, status: Unknown!"<<std::endl;
            MicroUnrollSolver.reset();
            //MicroUnrollSolver.pop();
            return;
        }
        MicroUnrollSolver.add(mitre);
        
        std::ofstream smtFile(fileName);
        smtFile<<MicroUnrollSolver<<std::endl;

        //MicroUnrollSolver.pop();
        MicroUnrollSolver.reset();
    }
    void MicroUnroller::EqOffline(const std::string & fileName, MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2, py::list & assumps)
    {

        // first let's look it up in the two 
        npair_t & np1 = m1->m_pUAbstraction->findInMap(n1)->second;
        npair_t & np2 = m2->m_pUAbstraction->findInMap(n2)->second;

        z3::expr e1 = m1->getNodeOnFrame(m1->frame(), np1.var);
        z3::expr e2 = m2->getNodeOnFrame(m2->frame(), np2.var);

        z3::expr mitre = (e1 != e2).simplify();


        MicroUnrollSolver.reset();

        //MicroUnrollSolver.push();
        m1->InsertAssumptions();
        m2->InsertAssumptions();
        // Insert More assertions!
        boost::python::ssize_t len = boost::python::len( assumps );
        for (boost::python::ssize_t i=0;i<len;i++) {
            boost::python::object elem = assumps[i];
            boost::python::object item = boost::python::extract<boost::python::tuple> (elem);
            boost::python::extract<unsigned> getIdx(item[0]);
            boost::python::extract<std::string> getName1(item[1]);
            boost::python::extract<std::string> getName2(item[2]);
            if (!getIdx.check() )
                throw  PyILAException(PyExc_TypeError, "Frame number must be an integer");
            if (!getName1.check() || !getName2.check() )
                throw PyILAException(PyExc_TypeError, "Frame pair must be a pair of string");

            unsigned idx = getIdx();
            std::string name1 = getName1();
            std::string name2 = getName2();
            // now we can insert them
            ILA_ASSERT( m1->frame() >= idx , "Assumption is on a wrong frame." );
            ILA_ASSERT( m2->frame() >= idx , "Assumption is on a wrong frame." );

            npair_t & npa1 = m1->m_pUAbstraction->findInMap(name1)->second;
            npair_t & npa2 = m2->m_pUAbstraction->findInMap(name2)->second;
            z3::expr ep1 = m1->getNodeOnFrame(idx, npa1.var);
            z3::expr ep2 = m2->getNodeOnFrame(idx, npa2.var);

            MicroUnrollSolver.add( (ep1 == ep2).simplify() );
        }

        if(MicroUnrollSolver.check() == z3::unsat) {
            std::cerr<<"Assumptions do not hold, status: Unknown!"<<std::endl;
            MicroUnrollSolver.reset();
            //MicroUnrollSolver.pop();
            return;
        }
        MicroUnrollSolver.add(mitre);

        std::ofstream smtFile(fileName);
        smtFile<<MicroUnrollSolver<<std::endl;
        
        MicroUnrollSolver.reset();
        //MicroUnrollSolver.pop();
    }
  
    bool MicroUnroller::EqCheck(MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2)
    {
        // first let's look it up in the two 
        npair_t & np1 = m1->m_pUAbstraction->findInMap(n1)->second;
        npair_t & np2 = m2->m_pUAbstraction->findInMap(n2)->second;

        z3::expr e1 = m1->getNodeOnFrame(m1->frame(), np1.var);
        z3::expr e2 = m2->getNodeOnFrame(m2->frame(), np2.var);

        z3::expr mitre = (e1 != e2).simplify();
    
        MicroUnrollSolver.reset();
        //MicroUnrollSolver.push();
        m1->InsertAssumptions();
        m2->InsertAssumptions();

        if(MicroUnrollSolver.check() == z3::unsat) {
            std::cerr<<"Assumptions do not hold, status: Unknown!"<<std::endl;
            return false;
        }
        MicroUnrollSolver.add(mitre);
        bool result = checkMiter(MicroUnrollSolver,e1,e2,m1,m2);

        MicroUnrollSolver.reset();
        //MicroUnrollSolver.pop();
        return result;
    }
    bool MicroUnroller::EqCheck(MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2, py::list & assupList)
    {
        // first let's look it up in the two 
        npair_t & np1 = m1->m_pUAbstraction->findInMap(n1)->second;
        npair_t & np2 = m2->m_pUAbstraction->findInMap(n2)->second;

        z3::expr e1 = m1->getNodeOnFrame(m1->frame(), np1.var);
        z3::expr e2 = m2->getNodeOnFrame(m2->frame(), np2.var);

        z3::expr mitre = (e1 != e2).simplify();

        //MicroUnrollSolver.push();
        MicroUnrollSolver.reset();

        // prepare sublist
        z3::expr_vector subs_src(MicroUnrollContext);
        z3::expr_vector subs_dst(MicroUnrollContext);
        
        // Insert More assertions!
        boost::python::ssize_t len = boost::python::len( assupList );
        log2("Unroller")<<"checkListLen:"<<len<<std::endl;
        for (boost::python::ssize_t i=0;i<len;i++) {
            boost::python::object elem = assupList[i];
            boost::python::object item = boost::python::extract<boost::python::tuple> (elem);
            boost::python::extract<unsigned> getIdx(item[0]);
            boost::python::extract<std::string> getName1(item[1]);
            boost::python::extract<std::string> getName2(item[2]);
            if (!getIdx.check() )
                throw  PyILAException(PyExc_TypeError, "Frame number must be an integer");
            if (!getName1.check() || !getName2.check() )
                throw PyILAException(PyExc_TypeError, "Frame pair must be a pair of string");

            unsigned idx = getIdx();
            std::string name1 = getName1();
            std::string name2 = getName2();
            // now we can insert them
            ILA_ASSERT( m1->frame() >= idx , "Assumption is on a wrong frame." );
            ILA_ASSERT( m2->frame() >= idx , "Assumption is on a wrong frame." );

            npair_t & npa1 = m1->m_pUAbstraction->findInMap(name1)->second;
            npair_t & npa2 = m2->m_pUAbstraction->findInMap(name2)->second;
            z3::expr ep1 = m1->getNodeOnFrame(idx, npa1.var);
            z3::expr ep2 = m2->getNodeOnFrame(idx, npa2.var);

            MicroUnrollSolver.add( (ep1 == ep2).simplify() );
            
            log2("Unroller")<<"Add Assumpt :" <<(ep1 == ep2) <<std::endl;
            subs_src.push_back(ep1);
            subs_dst.push_back(ep2);
        }
        log2("Unroller")<<"Will replace:"<<std::endl;
        for (unsigned i=0;i<subs_src.size();i++) {
            log2("Unroller")<<subs_src[i]<<" -> "<<subs_dst[i]<<std::endl;
            }

        m1->InsertAssumptSub(subs_src,subs_dst);
        m2->InsertAssumptSub(subs_src,subs_dst);

        //std::cerr<<"before checking..."<<std::endl;
        if(MicroUnrollSolver.check() == z3::unsat) {
            std::cerr<<"Assumptions do not hold, status: Unknown!"<<std::endl;
            //MicroUnrollSolver.pop();
            MicroUnrollSolver.reset();
            return false;
        }
        
        MicroUnrollSolver.add(mitre.substitute(subs_src,subs_dst));
        //std::cerr<<"before checking 1..."<<std::endl;
        bool result = checkMiter(MicroUnrollSolver,e1,e2,m1,m2);

        MicroUnrollSolver.reset();
        //MicroUnrollSolver.pop();
        
        //std::cerr<<"end checking..."<<std::endl;
        return result;
    }

    void MicroUnroller::debugFrame()
    {
#ifdef _DEBUG_
        log1("Unroller")<<"(!) CURRENT FRAMES: 0-"<<frame()<<std::endl;
        for (unsigned fn =0; fn <= frame(); fn++)
        {
            for (unsigned slot =0;slot< m_vOutputs[fn].size(); slot ++)
            {
                log1("Unroller")<<"Frame ("<<fn<<","<<slot<<") : "<<m_vOutputs[fn][slot]<<std::endl;
            }
        }
        log1("Unroller")<<"(!) CURRENT FRAMES: END"<<std::endl;
#endif
    }
    void MicroUnroller::EvalEachFrame(z3::model &m, MicroUnroller *u , ostream & cexf)
    {

        cexf << "Abstraction:"<<u->m_pAbstraction->getName()<<std::endl;
        cexf << "UAbstraction:"<<u->m_pUAbstraction->getName()<<std::endl;
        cexf << "Model:"<<std::endl;
        cexf << m;
        cexf << "\nFrames Eval:" << std::endl;
        unsigned nFrame = u->frame();
        for(unsigned idx = 1; idx <= nFrame; idx ++ ) {
            cexf << "<Frame "<<idx<< ">"<<std::endl;
            for(auto &ni: u->m_mStateIndices) {
                cexf << ni.first->getName() << ": ";
                z3::expr eval_result = m.eval( u->m_vOutputs[idx][ ni.second ] ).simplify();
                const MemVar* memvar;
                Z3ExprAdapter z3expr(MicroUnrollContext,frame2suffix(1,false));
                if ((memvar = dynamic_cast<const MemVar*>(ni.first)))
                    cexf<<MemValues(z3expr,m,memvar)<<std::endl;
                else
                    cexf << eval_result <<std::endl;
            }
        }
    }

    bool MicroUnroller::checkMiter(z3::solver& S, z3::expr& e1, z3::expr& e2, MicroUnroller *u1, MicroUnroller *u2)
    {
        using namespace z3;

        
        auto r = S.check();
        if (r == sat) {
            z3::model m = S.get_model();
            z3::expr m1 = m.eval(e1);
            z3::expr m2 = m.eval(e2);
            //std::cout << m << std::endl;
            std::cout << m1 << std::endl;
            std::cout << m2 << std::endl;

            std::ofstream cexf("cex.out");
            EvalEachFrame(m, u1, cexf);
            EvalEachFrame(m, u2, cexf);
            std::cerr<<"CounterExample has been dumped to cex.out"<<std::endl;

            return false;
        } else if (r == unsat) {
            return true;
        } else {
            throw PyILAException(PyExc_RuntimeError, "Indeterminate result from Z3.");
            return false;
        }
    }

}

