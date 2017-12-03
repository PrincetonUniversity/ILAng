#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

#include <set>
#include <map>
#include <vector>
#include <string>
#include <boost/python.hpp>

#include <common.hpp>
#include <ast.hpp>
#include <smt.hpp>
#include <imexport.hpp>
#include <VerilogExport.hpp>
#include <cppsimgen.hpp>
#include <genCBMC.hpp>
#include <MicroUnroller.hpp>
#include <boogie.hpp>
#include <horn.hpp>

namespace ila
{
    class Abstraction;
    class AbstractionWrapper;
    class MicroEQCheck;
    typedef boost::shared_ptr<Abstraction> abstraction_ptr_t;

    struct assump_visitor_i {
        virtual void useAssump(const nptr_t& a) = 0;
    };

    class Abstraction
    {
    public:
        // type of the state element/input.
        enum state_t { INP, REG, BIT, MEM, FUN };

        struct uabstraction_t {
            // when is the abstraction valid.
            nptr_t valid;
            // the abstraction.
            abstraction_ptr_t abs; 
        };

        // list of microabstractions.
        typedef std::map<std::string, uabstraction_t> uabs_map_t;

    private:
        static int objCnt;
        int MAX_SYN_ITER;
    protected:

        // parent abstraction.
        Abstraction* parent;

        // name of this abstraction.
        const std::string name;

        // list of known names.
        std::map<std::string, state_t> names;

        // list of inputs
        nmap_t inps;
        // list of registers.
        nmap_t regs;
        // list of bits.
        nmap_t bits;
        // list of memories.
        nmap_t mems;
        // list of functions.
        nmap_t funs;

        // fetch
        nptr_t fetchExpr;
        nptr_t fetchValid;

        // decode
        nptr_vec_t decodeExprs;

        // assumptions.
        nptr_vec_t assumps;

        // list of sub-abstractions.
        uabs_map_t uabs;
        
        void initMap(nmap_t& from_m, nmap_t& to_m);

        void extractModelValues(
            Z3ExprAdapter& c,
            z3::model& m, 
            py::dict& result
        );

        NodeRef* getVar(const nmap_t& m, const std::string& name);
        void addVar(state_t st, nmap_t& m, nptr_t& n);

    public:
        int paramSyn;
        int reduceWhenImport;
        VlgExportConfig vlgExpConfig;

        // Constructor.
        Abstraction(const std::string& name);

        // Constructor for a micro-abstraction
        Abstraction(Abstraction* parent, const std::string& name);

        // Destructor.
        ~Abstraction();

        // Get abstraction name
        const std::string & getName() const {return name;}
        // Get a new ID.
        static int getObjId();

        // Create a bitvector input.
        NodeRef* addInp(const std::string& name, int width);

        // Create a boolean variable.
        NodeRef* addBit(const std::string& name);

        // Create a bitvector variable.
        NodeRef* addReg(const std::string& name, int width);

        // Create a memory.
        NodeRef* addMem(const std::string& name, int addrW, int dataW);

        // Create a function.
        NodeRef* addFun(const std::string& name, int retW, const py::list& l);

        // Get an existing input port
        NodeRef* getInp(const std::string& name);
        // Get an existing boolean.
        NodeRef* getBit(const std::string& name);
        // Get an existing bitvector.
        NodeRef* getReg(const std::string& name);
        // Get an existing memory.
        NodeRef* getMem(const std::string& name);
        // Get an existing function.
        NodeRef* getFun(const std::string& name);
        // Get and existing stage variable.
        NodeRef* getStage(const std::string& name);

        // add a var if it does not exist.
        void addVar(nptr_t& nref);

        // Set the init value for this var.
        void setInit(const std::string& name, NodeRef* n);
        // Get the initial value for this var.
        NodeRef* getInit(const std::string& name) const;
        // Set a predicate on the initial value.
        void setIpred(const std::string& name, NodeRef* n);
        // Get the predicate on the initial value.
        NodeRef* getIpred(const std::string& name) const;

        // Set the next template for this var.
        void setNext(const std::string& name, NodeRef* n);
        // Get the next template.
        NodeRef* getNext(const std::string& name) const;
        // Get the next template for the i-th instruction.
        NodeRef* getNextI(const std::string& name, int i) const;

        // Create a uabstraction.
        AbstractionWrapper* addUAbs(
            const std::string& name,
            NodeRef* valid);
        // Get an existing uabstraction.
        AbstractionWrapper* getUAbs(const std::string& name);
        // Connect a microinstruction.
        void connectUInst(
            const std::string& name, 
            const abstraction_ptr_t& uabs);

        // Create a bitvector constant with a long integer.
        static NodeRef* bvConstLong(py::long_ l, int width);
        // Create a bitvector constant with an integer.
        static NodeRef* bvConstInt(unsigned int l, int width);

        // Create a boolean constant (from a bool).
        static NodeRef* boolConstB(bool b);
        // Create a boolean constant (from an integer: nonzero = true).
        static NodeRef* boolConstI(int b);
        // Create a boolean constant (from an python long).
        static NodeRef* boolConstL(py::long_ b);

        // Create a memory constant (from a memvalues object).
        static NodeRef* memConst(const MemValues& mv);

        // return the current fetch expression.
        NodeRef* getFetchExpr() const;
        // set the fetch expression.
        void setFetchExpr(NodeRef* expr);
        // return the fetch valid expression.
        NodeRef* getFetchValid() const;
        
        nptr_t getFetchValidNode() const;
            
        // set the fetch valid expresssion.
        void setFetchValid(NodeRef* expr);
        // set decode.
        void setDecodeExpressions(const py::list& l);
        // get decode expressions.
        py::list getDecodeExpressions() const;
        const nptr_vec_t& getDecodeNodes() const;

        // add an assumption.
        void addAssumption(NodeRef* expr);
        // get all assumptions.
        py::list getAllAssumptions() const;

        // the real synthesize function.
        void synthesizeAll(PyObject* fun);

        // synthesize only one register.
        void synthesizeReg(const std::string& name, PyObject* fun);

        // the synthesis function.
        NodeRef* synthesizeElement(
            const std::string& name, 
            NodeRef* expr, PyObject* fun);

        // the export function that export only one expression.
        void exportOneToFile(NodeRef* node,
                             const std::string& fileName) const;
        // the export function that export a list of expressions.
        void exportListToFile(const py::list& l,
                              const std::string& fileName) const;
        // the export function that export the overall model.
        void exportAllToFile(const std::string& fileName) const;

        // the export function that export to a outstream
        void exportAllToStream(std::ofstream &out) const;

        // generate verilog file that is equivelant to the ILA
        void generateVerilogToFile(const std::string &fileName) const;

        // generate verilog file that is equivelant to the ILA with a different top-level module name
        void generateVerilogToFile(const std::string &fileName, const std::string &topModName) const;

        
        // the import function that import only one expression.
        NodeRef* importOneFromFile(const std::string& fileName);
        // the import function that import a list of expression.
        py::list importListFromFile(const std::string& fileName);
        // the import function that import the overall model.
        void importAllFromFile(const std::string& fileName);
        // the import function that import the overall ILA abstraction from Stream
        void importAllFromStream(std::ifstream &in, bool Clear);        

        // the simulator generating function, output to one file.
        void generateSimToFile(const std::string& fileName) const;
        // the simulator generating function, output to seperated files in dir.
        void generateSimToDir(const std::string& dirName) const;

        // the CBMC C generating function, output to one file.
        void generateCbmcCtoFile(const std::string & fileName) const;
        // the CBMC C generating function, output to seperated files in dir.
        void generateCbmcCtoDir(const std::string & dirName) const;

        // check equality function.
        bool areEqual(NodeRef* left, NodeRef* right) const;
        // check quality under assumption
        bool areEqualAssump(NodeRef* assump, NodeRef* left, NodeRef* right);
        // check after unrolling.
        bool areEqualUnrolled(unsigned n, NodeRef* reg, NodeRef* exp);
        // unroll two abstractions and check
        static bool bmc(unsigned n, Abstraction *a, NodeRef *r, bool init, NodeRef * initAssump);
        static bool bmc(
            unsigned n1, Abstraction* a1, NodeRef* r1, 
            unsigned n2, Abstraction* a2, NodeRef* r2);

        // unroll two abstraction including microabstraction and check
        static bool EQcheckSimple(Abstraction* a1, Abstraction *a2);

        // convert this abstraction to boogie.
        void toBoogie(const std::string& filename);

        // convert this abstraction to horn clauses.
        void hornifyAll(const std::string& fileName);
        // convert one node to horn clause,
        void hornifyNode(NodeRef* node, const std::string& ruleName);
        // generate mapping for instructions. (Interleave/Blocking)
        void generateHornMapping (const std::string& type);
        // dump horn clauses to file.
        void exportHornToFile(const std::string& fileName);
        // set flag to hornify ITE as node.
        void hornifyIteAsNode(bool iteAsNode);
        // set flag to hornify bitvector as Int.
        void hornifyBvAsInt(bool bvAsInt);
        // create an instruction with name i and decode d.
        void addHornInstr (const std::string& i, NodeRef* d);
        // add next state function n for state s to (child-)instruction i.
        void addHornNext (const std::string& i, const std::string& s, 
                          NodeRef* n);
        // create a child-instruction with name c and decode d to instr i.
        void addHornChild (const std::string& c, const std::string& i, 
                           NodeRef* d);

        // get memories.
        const nmap_t& getMems() const { return mems; }
        // get (bitvector) inputs.
        const nmap_t& getInps() const { return inps; }
        // get bitvectors.
        const nmap_t& getRegs() const { return regs; }
        // get booleans.
        const nmap_t& getBits() const { return bits; }
        // get functions.
        const nmap_t& getFuns() const { return funs; }

        // visit each assumption.
        void forEachAssump(assump_visitor_i& i) const;
        // get all assumptions in a vector.
        void getAllAssumptions(nptr_vec_t& assump_vec) const;

        // collect all assumptions in a vector.
        struct assump_collector_t : public assump_visitor_i {
            nptr_vec_t& vec;
            assump_collector_t(nptr_vec_t& v) : vec(v) {}
            void useAssump(const nptr_t& a);
        };
            
        // accessors.
        nptr_t getFetchExprRef() const { return fetchExpr; }
        nptr_t getFetchValidRef() const { return fetchValid; }
        nptr_vec_t getDecodeExprs() const { return decodeExprs; }
        const npair_t* getMapEntry(const std::string& name) const;
        bool isInput(const std::string& name) const {
            auto pos = names.find(name);
            if (pos == names.end()) return false;
            else return pos->second == INP;
        }

        friend class Synthesizer;
        friend class BoogieTranslator;
        friend unsigned DetermineUnrollBound( Abstraction * pAbs, const std::string & nodeName);
        friend class MicroUnroller;

    protected:
        nptr_t _synthesize(
            const std::string& name, 
            const nptr_vec_t& assumps, const nptr_t& expr,
            PyObject* pyfun);

        bool checkAndInsertName(state_t st, const std::string& name);

        // does the next expr exist?
        bool doesNextExist(const nmap_t& m) const;
        // which is the map containing this node?
        nmap_t* getMap(const std::string& name, NodeRef* n);
        // same as above, but use only name.
        nmap_t* getMap(const std::string& name);
        // what is the map containing this name?
        nmap_t::const_iterator findInMap(const std::string& name) const;
        nmap_t::iterator findInMap(const std::string& name);
        
        nmap_t::const_iterator findInMapNoExcept(const std::string& name) const;
        nmap_t::iterator findInMapNoExcept(const std::string& name);
        nmap_t::const_iterator MapEnd() const;
        nmap_t::iterator MapEnd();
        
        friend class AbstractionWrapper;

    private:
        // function reduce helper
        mutable FuncReduction funcReducer;
        // horn clause translator.
        HornTranslator* _ht;
        // The simulator generating function.
        CppSimGen* generateSim(bool hier) const;
        // CBMC C generation
        CVerifGen* generateCBMCC(bool hier) const;
        // Set inputs, states, and functions to the simulator generator.
        void addVarToSimulator(CppSimGen* gen) const;
        // Set next value to the function.
        void setUpdateToFunction(CppSimGen* gen, CppFun* fun, 
                                 nptr_t valid, bool doHier = false) const;

    };

    // This class contains a shared pointer to an underlying
    // abstraction.  We use this to wrap up objects and pass them
    // around in python and the shared_ptr does the refcounting for us.
    struct AbstractionWrapper
    {
        abstraction_ptr_t abs;

        // constructor.
        AbstractionWrapper(const std::string& name) 
          : abs(new Abstraction(name)) 
        {
        }

        // constructor for microabstraction.
        AbstractionWrapper(Abstraction* parent, 
                           const std::string& name)
          : abs(new Abstraction(parent, name))
        {
        }

        // constructor with existing pointer.
        AbstractionWrapper(const abstraction_ptr_t& a)
          : abs(a)
        {
        }

        // destructor.
        ~AbstractionWrapper() {}; 

        // Create a bitvector input.
        NodeRef* addInp(const std::string& name, int width) {
            return abs->addInp(name, width);
        }

        // Create a boolean variable.
        NodeRef* addBit(const std::string& name) {
            return abs->addBit(name);
        }

        // Create a bitvector variable.
        NodeRef* addReg(const std::string& name, int width) {
            return abs->addReg(name, width);
        }

        // Create a memory.
        NodeRef* addMem(const std::string& name, int addrW, int dataW) {
            return abs->addMem(name, addrW, dataW);
        }

        // Create a function.
        NodeRef* addFun(const std::string& name, int retW, const py::list& l) {
            return abs->addFun(name, retW, l);
        }
        
        // Get an existing input port
        NodeRef* getInp(const std::string& name) {
            return abs->getInp(name);
        }
        
        // Get an existing boolean.
        NodeRef* getBit(const std::string& name) {
            return abs->getBit(name);
        }

        // Get an existing bitvector.
        NodeRef* getReg(const std::string& name) {
            return abs->getReg(name);
        }

        // Get an existing memory.
        NodeRef* getMem(const std::string& name) {
            return abs->getMem(name);
        }

        // Get an existing function.
        NodeRef* getFun(const std::string& name) {
            return abs->getFun(name);
        }

        // Set the init value for this var.
        void setInit(const std::string& name, NodeRef* n) {
            abs->setInit(name, n);
        }
        // Get the initial value for this var.
        NodeRef* getInit(const std::string& name) const {
            return abs->getInit(name);
        }

        // Set a predicate associated with the initial value.
        void setIpred(const std::string& name, NodeRef* n) {
            abs->setIpred(name, n);
        }
        // Get the predicate associated with the initial vlaue.
        NodeRef*getIpred(const std::string& name) const {
            return abs->getIpred(name);
        }

        // Set the next template for this var.
        void setNext(const std::string& name, NodeRef* n) {
            abs->setNext(name, n);
        }
        // Get the next template.
        NodeRef* getNext(const std::string& name) const {
            return abs->getNext(name);
        }

        // Get the next state fn for the ith instruction.
        NodeRef* getNextI(const std::string& name, int i) const {
            return abs->getNextI(name, i);
        }

        // Create a microabstraction.
        AbstractionWrapper* addUAbs(const std::string& name, NodeRef* valid)
        {
            return abs->addUAbs(name, valid);
        }
        // Get an existing microabstraction
        AbstractionWrapper* getUAbs(const std::string& name)
        {
            return abs->getUAbs(name);
        }
        // Connect a variable to its corresponding value in the ubs
        void connectUInst(const std::string& name, const AbstractionWrapper* uabs)
        {
            abs->connectUInst(name, uabs->abs);
        }


        // Create a bitvector constant with a long integer.
        NodeRef* bvConstLong(py::long_ l, int width) {
            return abs->bvConstLong(l, width);
        }
        static NodeRef* bvConstLongStatic(py::long_ l, int width) {
            return Abstraction::bvConstLong(l, width);
        }

        // Create a bitvector constant with an integer.
        NodeRef* bvConstInt(unsigned int l, int width) {
            return abs->bvConstInt(l, width);
        }
        static NodeRef* bvConstIntStatic(unsigned int l, int width) {
            return Abstraction::bvConstInt(l, width);
        }

        // Create a boolean constant (from a bool).
        NodeRef* boolConstB(bool b) {
            return abs->boolConstB(b);
        }
        static NodeRef* boolConstBStatic(bool b) {
            return Abstraction::boolConstB(b);
        }

        // Create a boolean constant (from an integer: nonzero = true).
        NodeRef* boolConstI(int b) {
            return abs->boolConstI(b);
        }
        static NodeRef* boolConstIStatic(int b) {
            return Abstraction::boolConstI(b);
        }

        // Create a boolean constant (from an python long).
        NodeRef* boolConstL(py::long_ b) {
            return abs->boolConstL(b);
        }
        static NodeRef* boolConstLStatic(py::long_ b) {
            return Abstraction::boolConstL(b);
        }

        // Create a memory constant (from a memvalues object).
        NodeRef* memConst(const MemValues& mv) {
            return abs->memConst(mv);
        }
        static NodeRef* memConstStatic(const MemValues& mv) {
            return Abstraction::memConst(mv);
        }

        // return the current fetch expression.
        NodeRef* getFetchExpr() const {
            return abs->getFetchExpr();
        }

        // set the fetch expression.
        void setFetchExpr(NodeRef* expr) {
            abs->setFetchExpr(expr);
        }

        // return the fetch valid expression.
        NodeRef* getFetchValid() const {
            return abs->getFetchValid();
        }

        // set the fetch valid expresssion.
        void setFetchValid(NodeRef* expr) {
            abs->setFetchValid(expr);
        }

        // set decode.
        void setDecodeExpressions(const py::list& l) {
            abs->setDecodeExpressions(l);
        }

        // get decode expressions.
        py::list getDecodeExpressions() const {
            return abs->getDecodeExpressions();
        }

        // add an assumption.
        void addAssumption(NodeRef* expr) {
            abs->addAssumption(expr);
        }

        // get all assumptions.
        py::list getAllAssumptions() const {
            return abs->getAllAssumptions();
        }

        // the real synthesize function.
        void synthesizeAll(PyObject* fun) {
            return abs->synthesizeAll(fun);
        }

        // synthesize only one register.
        void synthesizeReg(const std::string& name, PyObject* fun) {
            return abs->synthesizeReg(name, fun);
        }

        // the synthesis function.
        NodeRef* synthesizeElement(
            const std::string& name, 
            NodeRef* expr, PyObject* fun) {
            return abs->synthesizeElement(name, expr, fun);
        }

        // the export function that export only one expression.
        void exportOneToFile(NodeRef* node,
                             const std::string& fileName) const 
        {
             abs->exportOneToFile(node, fileName);
        }

        // the export function that export a list of expressions.
        void exportListToFile(const py::list& l,
                              const std::string& fileName) const
        {
            abs->exportListToFile(l, fileName);
        }

        // the export function that export the overall model.
        void exportAllToFile(const std::string& fileName) const
        {
            abs->exportAllToFile(fileName);
        }

        void generateVerilogToFile( const std::string & fileName) const
        {
            abs->generateVerilogToFile(fileName);
        }
        void generateVerilogModule( const std::string & fileName, const std::string &modName) const
        {
            abs->generateVerilogToFile(fileName,modName);
        }

        // the import function that import only one expression.
        NodeRef* importOneFromFile(const std::string& fileName)
        {
            return abs->importOneFromFile(fileName);
        }

        // the improt function that import a list of expressions.
        py::list importListFromFile(const std::string& fileName)
        {
            return abs->importListFromFile(fileName);
        }

        // the import function that import the overall model.
        void importAllFromFile(const std::string& fileName)
        {
            abs->importAllFromFile(fileName);
        }

        // the simulator generating function.
        void generateSimToFile(const std::string& fileName) const
        {
            abs->generateSimToFile(fileName);
        }

        void generateSimToDir(const std::string& dirName) const
        {
            abs->generateSimToDir(dirName);
        }

        void generateCbmcCtoFile(const std::string& fileName) const
        {
            abs->generateCbmcCtoFile(fileName);
        }
        
        void generateCbmcCtoDir(const std::string& dirName) const
        {
            abs->generateCbmcCtoDir(dirName);
        }

        // check equality function.
        bool areEqual(NodeRef* left, NodeRef* right) const
        {
            return abs->areEqual(left, right);
        }

        // check quality under assumption
        bool areEqualAssump(NodeRef* assump, NodeRef* left, NodeRef* right)
        {
            return abs->areEqualAssump(assump, left, right);
        }

        // check equality after unrolling.
        bool areEqualUnrolled(unsigned n, NodeRef* reg, NodeRef* exp)
        {
            return abs->areEqualUnrolled(n, reg, exp);
        }
        bool bmcInit(NodeRef * assertion, unsigned n, bool init)
        {
            Abstraction *aptr = abs.get();
            return Abstraction::bmc(n, aptr, assertion, init, NULL);
        }
        bool bmcCond(NodeRef * assertion, unsigned n, NodeRef *assumpt)
        {
            Abstraction *aptr = abs.get();
            return Abstraction::bmc(n, aptr, assertion, false, assumpt);
        }
        
        static bool bmc(
            unsigned n1, AbstractionWrapper* a1, NodeRef* r1, 
            unsigned n2, AbstractionWrapper* a2, NodeRef* r2)
        {
            Abstraction* a1ptr = a1->abs.get();
            Abstraction* a2ptr = a2->abs.get();

            return Abstraction::bmc(n1, a1ptr, r1, n2, a2ptr, r2);
        }

        static bool EQcheckSimple(
            AbstractionWrapper* a1, AbstractionWrapper* a2)
        {
            Abstraction* a1ptr = a1->abs.get();
            Abstraction* a2ptr = a2->abs.get();
            
            return Abstraction::EQcheckSimple(a1ptr,a2ptr);
        }
        
        static bool EQcheck(
                    MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2)
        {
            return MicroUnroller::EqCheck(m1,m2,n1,n2);
        }
        static void EQcheckExport(const std::string & fn,
                    MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2)
        {
            MicroUnroller::EqOffline(fn,m1,m2,n1,n2);
        }

        static bool EQcheckWithAssump(
            MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2, py::list & assumps)
        {
            return MicroUnroller::EqCheck(m1,m2,n1,n2,assumps);
        }
        static void EQcheckWithAssumpExport(const std::string & fn,
            MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2, py::list & assumps)
        {
            MicroUnroller::EqOffline(fn,m1,m2,n1,n2,assumps);
        }

        MicroUnroller * newUnroller(AbstractionWrapper *uILA, bool initCondition)
        {
            return MicroUnroller::NewUnroller(this,uILA,initCondition);
        }

        void toBoogie(const std::string& name)
        {
            abs->toBoogie(name);
        }

        void hornifyAll(const std::string& name)
        {
            abs->hornifyAll(name);
        }

        void hornifyNode(NodeRef* node, const std::string& rule)
        {
            abs->hornifyNode(node, rule);
        }

        void generateHornMapping(const std::string& type)
        {
            abs->generateHornMapping(type);
        }

        void exportHornToFile(const std::string& fileName)
        {
            abs->exportHornToFile(fileName);
        }

        void hornifyIteAsNode(bool iteAsNode)
        {
            abs->hornifyIteAsNode(iteAsNode);
        }

        void hornifyBvAsInt(bool bvAsInt)
        {
            abs->hornifyBvAsInt(bvAsInt);
        }

        void addHornInstr(const std::string& i, NodeRef* d) 
        {
            abs->addHornInstr(i, d);
        }

        void addHornNext(const std::string& i, const std::string& s, NodeRef* n)
        {
            abs->addHornNext(i, s, n);
        }

        void addHornChild(const std::string& c, const std::string& i, NodeRef* d)
        {
            abs->addHornChild(c, i, d);
        }

        int getEnParamSyn() const {
            return abs->paramSyn;
        }

        void setEnParamSyn(int en) {
            abs->paramSyn = en;
        }

        void setVlgExpConfig(bool extMem, bool fAsM){
            abs->vlgExpConfig._extMem = extMem;
            abs->vlgExpConfig._fmodule = fAsM;
        }

        int getReduceWhenImport() const {
            return abs->reduceWhenImport;
        }

        void setReduceWhenImport(int en) {
            abs->reduceWhenImport = en;
        }

        std::string getName() const {
            return abs->name;
        }

        // get memories.
        const nmap_t& getMems() const { return abs->getMems(); }
        // get (bitvector) inputs.
        const nmap_t& getInps() const { return abs->getInps(); }
        // get bitvectors.
        const nmap_t& getRegs() const { return abs->getRegs(); }
        // get booleans.
        const nmap_t& getBits() const { return abs->getBits(); }
        // get functions.
        const nmap_t& getFuns() const { return abs->getFuns(); }
    };

}
#endif
