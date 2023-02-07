#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <vector>
#include <memory>

#include "hpl.h"

using namespace std;

enum HplFunction 
{
    kHplDlocmax = 0, 
    kHplPdmxswp, 
    kHplDlocswpN,
    kHplDscal,
    kHplDaxpy,
    kHplBcast,
    kHplDlaswp00N,
    kHplDtrsm,
    kHplDgemm
};

struct FunctionParam{
    int cmdSerialNum;
    HplFunction function;
    HPL_T_panel* panelInfo;
    int m;
    int i;
    int j;
    int lda;
    int ldl2;
    double* workSpace;
    double* curA;
    double* nxtA;
    int* ipiv;
};

class Utility {
    public:
    static void pushToMxuCmdQ(FunctionParam cmd);
    static void popFromMxuCmdQ(FunctionParam cmd);
    static void pushToCpuCmdQ(FunctionParam cmd);
    static void popFromCpuCmdQ(FunctionParam cmd);
    static bool isMxuCmdQValid();
    static bool isCpuCmdQValid();
    static bool isMxuCmdQAvailable();
    static bool isCpuCmdQAvailable();
    static int getCmdSerialNum();
    static std::shared_ptr<FunctionParam> getFreeFuncParam();

    private:
    Utility(){};
    static vector<FunctionParam> mxuCmdQueue;
    static vector<FunctionParam> cpuCmdQueue;
    static int cmdSerialNum;
};
#endif
