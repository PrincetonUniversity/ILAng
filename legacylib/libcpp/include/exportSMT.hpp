
#ifndef __EXPORT_SMT_DEFINED__
#define __EXPORT_SMT_DEFINED__

#include <iostream>
#include <ast.hpp>
#include <abstraction.hpp>
#include <smt.hpp>

namespace ila
{
    class SMTExport
    {
        typedef std::pair<std::string,int> nstage_t;
        typedef std::vector<nstage_t> nstage_vec_t;
    public:
        SMTExport(){}
        void exportSMT(std::ofstream & out, const Node * n, const std::string & name, int width);
        int get_width(const Node *n);
        bool isStageVar(const std::string &inpName, const nstage_vec_t & stageStore);
    };
}

#endif