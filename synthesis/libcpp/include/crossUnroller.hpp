#ifndef __CROSSUNROLLER_HPP_DEFINED__
#define __CROSSUNROLLER_HPP_DEFINED__

#include <set>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <boost/python.hpp>

#include <common.hpp>
#include <mcmCommon.hpp>
#include <ast.hpp>

#include <z3Converter.hpp>


namespace ila
{

    //-------------- z3Converter -------------------//

    class z3Converter: public Z3ExprAdapter
    {

        statelist_ptr_t m_pLocalStates;
        statelist_ptr_t m_pSharedStates;
        name2expr_t   * m_pIncomingResultDict;
        PiVarList_t *   m_pPiVarList;
        Step*           m_pStep;


    public:

        bool useOld()  { 
            return (!m_pLocalStates)||(!m_pSharedStates)|| (!m_pPiVarList) 
                || (!m_pIncomingResultDict) || (!m_pStep); } 

        z3Converter(z3::context& c, const std::string& suffix) : 
            Z3ExprAdapter(c,suffix), m_pLocalStates(NULL), m_pSharedStates(NULL),
            m_pIncomingResultDict(NULL), m_pPiVarList(NULL), m_pStep(NULL)
        {  }

        z3Converter(z3::context& c, const std::string& suffix,  // suffix should be given as the step's name
                statelist_ptr_t p_LocalStates, statelist_ptr_t p_SharedStates,
                name2expr_t * p_IncomingResultDict, PiVarList_t * p_PiVarList,
                Step * p_Step) : 
            Z3ExprAdapter(c,suffix), 
            m_pLocalStates(p_LocalStates), m_pSharedStates(p_SharedStates),
            m_pIncomingResultDict(p_IncomingResultDict), m_pPiVarList(p_PiVarList),
            m_pStep(p_Step)
        {  }

        virtual z3::expr getBoolVarExpr(const BoolVar* boolvar);

        virtual z3::expr getBitvectorVarExpr(const BitvectorVar* bvvar);

        virtual z3::expr getMemVarExpr(const MemVar* memvar);

        void setIncomingResultDict(name2expr_t   * p_IncomingResultDict)  
            { m_pIncomingResultDict = p_IncomingResultDict; }
        void resetStepPointer(Step * p_Step) { m_pStep = p_Step; }
        
        z3::expr newVar( const std::string & name, const Node * type) const;
        z3::expr stateReadFunc( const std::string & name, const  Node * type );

    };

    //-------------- z3Converter -------------------//

    class Step
    {
        friend class mcmUnroller;
        friend class TraceStep;
        friend class wvop;
        friend          class TSO;
        friend          class SC;
        friend          class MemoryModel;

        void initAndCheck();

    protected:
        std::string entityName;
        std::string name;
        int tid;

        statelist_ptr_t localStates;
        //stateset_t  Reads;
        stateset_t  Writes;


        std::shared_ptr<z3::expr> decodeExpr;

        name2expr_t resultDict;

        TsThatWritesVars_t *TsThatWritesVars;
        TsNameToObj_t *TsNameToObj;
        PiVarList_t *PiVarList;

        z3::context & m_pContext;

    public:
        z3::expr timestamp;

    public:
        Step(const std::string &p_entityName, 
            const std::string &name, 
            int tid, 
            TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
            statelist_ptr_t localStates,  // we don't want to copy this all along
            z3::context &c,
            const z3::expr &p_decodeExpr,
            PiVarList_t *PiVarList = NULL);

        //this helps to overwrite the timestamp
        Step(const std::string &p_entityName, 
            const std::string &name, 
            int tid, 
            TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
            statelist_ptr_t localStates,  // we don't want to copy this all along
            z3::context &c,
            const z3::expr &p_decodeExpr,
            z3::expr overwriteTs,
            PiVarList_t *PiVarList = NULL );


        virtual ~Step();

        std::string _entity() const {return entityName;}
        std::string getName() const { return name; }

        virtual std::string to_string() const = 0;

        // currently not used
        // const name2expr_t & getResultDict() {return resultDict;}


    };


    class InitStep: public Step
    {
            void init(z3Converter &initAdapter);
            void _initVar(z3Converter& z3expr, const std::string &name, const npair_t& p, bool allowInit);

        friend class mcmUnroller;
        friend          class TSO;
        friend          class SC;
        friend          class MemoryModel;

        protected:
            Abstraction *m_pAbs;

        public:
            InitStep(const std::string &p_entityName, 
                TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                statelist_ptr_t localStates,  // we don't what to copy this all along
                z3::context &c,
                z3Converter &initAdapter,
                int tid, 
                Abstraction * p_Abs,
                PiVarList_t *PiVarList = NULL
                );

            InitStep(const std::string &p_entityName, 
                TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                statelist_ptr_t localStates,  // we don't what to copy this all along
                z3::context &c,
                z3::expr overwriteTs,
                z3Converter &initAdapter,
                int tid, 
                Abstraction * p_Abs,
                PiVarList_t *PiVarList = NULL
                );

            virtual std::string to_string() const;
    };

    class EndStep: public Step
    {
            z3Converter &endAdapter;
        public:
            EndStep(const std::string &p_entityName, 
                TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                statelist_ptr_t localStates,  // we don't what to copy this all along
                z3::context &c,
                z3::expr overwriteTs,       // overwrite version
                z3Converter &endAdapter, // should bear ending suffix!
                int tid, 
                PiVarList_t *PiVarList = NULL );

            EndStep(const std::string &p_entityName,
                TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                statelist_ptr_t localStates,  // we don't what to copy this all along
                z3::context &c,
                z3Converter &endAdapter, // should bear ending suffix!
                int tid, 
                PiVarList_t *PiVarList = NULL );

            z3::expr getAssertFormula(Node *n);

            virtual std::string to_string() const;


            void printTsResultFromModel(z3::model & model);
    };

    // in this case we need to have a z3 converter for each step?
    // you cannot rely on the cache mechanism
    class TraceStep: public Step
    {
        
        Abstraction *m_pAbs;


        constraintList_t * m_pConstraintList;

        Instruction * m_pInstruction;

        MemoryModel &mm;
        z3Converter z3c;

        name2expr_t defVars; // this is for extracting models

        protected:
            // for tso
            tsList_t        m_wvopList;
            friend class wvop;
            friend          class TSO;
            friend          class SC;
            friend          class MemoryModel;

        public:
            TraceStep(Abstraction *p_Abs, 
                Instruction * pInstruction,
                //statelist_ptr_t SysSharedState, by default use local states
                TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                //statelist_ptr_t localStates,  // we don't what to copy this all along
                constraintList_t *ConstraintList,
                PiVarList_t *PiVarList,
                z3::context &c,
                int tid,
                MemoryModel &p_mm
                // z3::expr * overwriteTs = NULL not allowed?
                 );  // 

            z3::expr getAssertFormula(Node *n);

            void BuildFrame(Step * lastTraceStep);

            virtual std::string to_string() const;

            void printTsResultFromModel(z3::model & model);
    };


    class mcmUnroller
    {
        unsigned numOfEntity;
        noThread_t noThread;
        entity_t   entities;
        statelist_t states; 
        statelist_t memoryVars;
        statelist_t SysSharedStates;
        templateProgram_t templateProgram;

        Abstraction * m_pDummyGlobalAbs;

        // logging data structure
        TsThatWritesVars_t TsThatWritesVars;
        TsNameToObj_t      TsNameToObj;
        tsPOList_t         TsPOList;
        PiVarList_t        PiVarList;
        constraintList_t    ConstraintList;
        constraintList_t    runConstraintList;

        relTsLookupDict_t   relTsLookupDict;
        TsNameToRelLookup_t TsNameToRelLookup;


        InitStep  *globalBeginEvent;
        EndStep   *globalEndEvent;

        z3::expr * runTProp;
        static z3::context z3Context;
        z3::solver slv;
        z3Converter initAdapter;
        z3Converter endAdapter;

        // memory model
        MemoryModel &m_pMM;
        z3::model* p_model;

        // only for end adapter!
        statelist_t allStates;
        statelist_t noStates;
        name2expr_t emptyDict;

    protected:
        void findSharedStates(void); // will assign to entities.abs->sharedStates etc.
        void checkILANames(void);

        friend class MemoryModel;
        friend          class TSO;
        friend          class SC;
    public:

        mcmUnroller(
            const noThread_t &p_noThread, 
            const entity_t  &p_entities, 
            const templateProgram_t & p_templateProgram,
            Abstraction * p_DummyGlobalAbs,
            MemoryModel &p_MM
            );
        ~mcmUnroller();

        void unroll();
        void finalizePiFun(std::map<relId_t,relId_t> * rf_force = NULL);
        void addPropertyOnSingleFrames( Node * runProperty, ts2bool_t frameCond );
        void addPropertyOnEnding( Node * runProperty );

        void buildAndRunProp();
        void buildOrRunProp();
        bool pushInstConstraintAndCheck(); // true sat/ false unsat
        bool check(); // true sat/ false unsat

        void printModel(void);

    public:
        // litmus test helper function
        static relId_t litmus_getRelRefTuple(std::string &instName, std::string &eid, int rnd = 1);  // FIXME: not implemented
        void litmus_makeTsLocalFence(const relId_t & relRefTuple);          // FIXME: not implemented
        void enforce_CO_or_FR(relType tp, relId_t relId1, relId_t relId2);  // FIXME: not implemented


    public: // PYTHON INTERFACE
        static mcmUnroller * py_NewMCMUnroller(const py::list & nTh,
            const py::list & entity, const py::list & program, AbstractionWrapper * dummyInit, MemoryModel * p_mm);

        void py_unroll() { unroll(); }
        void py_finalizePiFun() { finalizePiFun(); }
        void py_addPropertyOnEnding( NodeRef * n );
        void py_ConnectByAnd() { buildAndRunProp(); }
        void py_ConnectByOr() { buildOrRunProp(); }
        bool py_pushInstConstraintAndCheck() { return pushInstConstraintAndCheck(); }
        bool py_check() { return  check(); }
        void py_printModel(void)  { printModel(); }


    };


}

#endif