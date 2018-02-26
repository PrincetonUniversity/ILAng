#ifndef __MCM_COMMON_HPP__
#define __MCM_COMMON_HPP__


#define IN(e,s) ( (s).find(e) != (s).end() )
#define IN_p(e,s) ( (s)->find(e) != (s)->end() )
#define INTERSECT(a,b,out) ( std::set_intersection((a).begin(),(a).end(), (b).begin(), (b).end(), std::inserter((out),(out).begin()) ) )

#define IMPLY_b(a,b) ((!(a))||(b))
#define EQ_b(a,b) (IMPLY_b(a,b) && IMPLY_b(b,a))


namespace ila {

    class mcmUnroller;
    class Step;
    class InitStep;
    class EndStep;
    class TraceStep;
    class z3Converter;
    class MemoryModel;
    class SC;
    class TSO;
    class wvop;

    typedef std::vector<int> noThread_t;
    typedef std::vector<std::string> single_thread_program_t;
    typedef std::vector<single_thread_program_t> templateProgram_t;
    typedef std::vector<std::shared_ptr<Step>> tsList_t;  // need deallocate!
    typedef std::vector<tsList_t>   tsPOList_t;

    typedef std::set<std::string> statelist_t;
    typedef statelist_t * statelist_ptr_t;
    typedef std::vector<Abstraction *> entity_t;
    //typedef std::shared_ptr<z3::expr>  z3expr_p;

    typedef std::set<Step *> stepset_t;
    typedef std::map<std::string, stepset_t> TsThatWritesVars_t;
    typedef std::map<std::string,Step *> TsNameToObj_t;
    typedef std::set<std::string> stateset_t;
    typedef std::tuple<std::string, z3::expr, Step *> PiVarListElem_t; // dict of tuples: z3PiVar, traceStepRef (timestamp)
    typedef std::map<std::string, PiVarListElem_t> PiVarList_t;

    typedef std::map<std::string, z3::expr> name2expr_t;
    typedef std::list<z3::expr> constraintList_t;

    // for litmus test : currently under tests!
    typedef std::tuple<std::string, std::string, int>  relId_t;
    typedef std::map<relId_t, Step *>  relTsLookupDict_t;
    typedef std::map<std::string, relId_t> TsNameToRelLookup_t;
    enum relType {CO,RF,FR,PO};

    // ts->bool function
    typedef bool (*ts2bool_t)(Step *);


    //std::string stepUniqueName();

    //bool is_init_event(Step * p);
}

#endif 