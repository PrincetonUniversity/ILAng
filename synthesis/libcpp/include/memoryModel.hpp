#ifndef __MEMORY_MODEL_HPP_DEFINED__
#define __MEMORY_MODEL_HPP_DEFINED__


namespace ila
{

    typedef std::list< std::tuple<std::string, z3::expr, Node *> > tsDefsGroup_t;


    class MemoryModel
    {
    public:
        virtual void bookKeepWrite( TraceStep * ts , TsNameToObj_t * p_TsNameToObj, TsThatWritesVars_t * p_TsThatWritesVars ) = 0;
        virtual void regWriteView ( const std::string & sname, z3::expr & z3def, TraceStep * ts , Node * type ) = 0;
        virtual void createWriteView( TraceStep * ts, TsNameToObj_t * p_TsNameToObj , 
            TsThatWritesVars_t * p_TsThatWritesVars,  constraintList_t *ConstraintList ) = 0;
        virtual void addPORelatedHB(constraintList_t *ConstraintList ,tsPOList_t *TsPOList) = 0;
        virtual void make_thread_local_fence( TraceStep * fence_ts, tsPOList_t *TsPOList, constraintList_t *ConstraintList) = 0;
        virtual z3::expr build_rf_constraint(std::string & sname, z3::expr & piVar, TsThatWritesVars_t * p_TsThatWritesVars,
            Step * read, Step * write ) = 0;
    protected:
        virtual z3::expr co_hb(Step * w1, Step * w2) = 0;
        virtual z3::expr fr_hb(Step * r,  Step * w ) = 0;
    public:
        virtual void DEBUG_printPossibleReadFrom(PiVarList_t * PiVarList, TsThatWritesVars_t * p_TsThatWritesVars) = 0;
        virtual void DEBUG_extractViewResultForTs(TraceStep * ts, z3::model & model) = 0;

        virtual std::string What() = 0;
    };


    class MCMWrapper
    {
        public:
            MCMWrapper(const std::shared_ptr<MemoryModel> &m ) : mcm(m) {}
            std::shared_ptr<MemoryModel> mcm;
            std::string What() { return mcm->What(); }
    };


    class SC : public MemoryModel
    {
    public:
        virtual void bookKeepWrite( TraceStep * ts , TsNameToObj_t * p_TsNameToObj, TsThatWritesVars_t * p_TsThatWritesVars );
        virtual void regWriteView ( const std::string & sname, z3::expr & z3def, TraceStep * ts , Node * type );
        virtual void createWriteView( TraceStep * ts, TsNameToObj_t * p_TsNameToObj , 
            TsThatWritesVars_t * p_TsThatWritesVars,  constraintList_t *ConstraintList );
        virtual void addPORelatedHB(constraintList_t *ConstraintList ,tsPOList_t *TsPOList);
        virtual void make_thread_local_fence( TraceStep * fence_ts, tsPOList_t *TsPOList, constraintList_t *ConstraintList);
        virtual z3::expr build_rf_constraint(std::string & sname, z3::expr & piVar, TsThatWritesVars_t * p_TsThatWritesVars,
            Step * read, Step * write );
    protected:
        virtual z3::expr co_hb(Step * w1, Step * w2);
        virtual z3::expr fr_hb(Step * r,  Step * w );
    public:
        virtual void DEBUG_printPossibleReadFrom(PiVarList_t * PiVarList, TsThatWritesVars_t * p_TsThatWritesVars);
        virtual void DEBUG_extractViewResultForTs(TraceStep * ts, z3::model & model);

        virtual std::string What() {return "SC: MemoryModel";}

    };

    class wvop : public Step
    {
    public:
        virtual std::string to_string() const;

        wvop(const TraceStep & ts,
            tsDefsGroup_t & tsDefsGroup,
            TsThatWritesVars_t *TsThatWritesVars, 
            constraintList_t * p_ConstraintList,
            Step * globalEndStep);

    };

    class TSO: public MemoryModel
    {

    public:
        virtual void bookKeepWrite( TraceStep * ts , TsNameToObj_t * p_TsNameToObj, TsThatWritesVars_t * p_TsThatWritesVars );
        virtual void regWriteView ( const std::string & sname, z3::expr & z3def, TraceStep * ts , Node * type );
        virtual void createWriteView( TraceStep * ts, TsNameToObj_t * p_TsNameToObj , 
            TsThatWritesVars_t * p_TsThatWritesVars,  constraintList_t *ConstraintList );
        virtual void addPORelatedHB(constraintList_t *ConstraintList ,tsPOList_t *TsPOList);
        virtual void make_thread_local_fence( TraceStep * fence_ts, tsPOList_t *TsPOList, constraintList_t *ConstraintList);
        virtual z3::expr build_rf_constraint(std::string & sname, z3::expr & piVar, TsThatWritesVars_t * p_TsThatWritesVars,
            Step * read, Step * write );
    protected:
        virtual z3::expr co_hb(Step * w1, Step * w2);
        virtual z3::expr fr_hb(Step * r,  Step * w );

        TraceStep * convert_to_ts(Step * w);

        tsDefsGroup_t tsDefsGroup;

    public:
        virtual void DEBUG_printPossibleReadFrom(PiVarList_t * PiVarList, TsThatWritesVars_t * p_TsThatWritesVars);
        virtual void DEBUG_extractViewResultForTs(TraceStep * ts, z3::model & model);


        virtual std::string What() {return "TSO: MemoryModel"; }
    };

    class CustomModel: public MemoryModel
    {
        // TODO: add a parser layer to parse the Axioms
    };
}

#endif