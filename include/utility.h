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
    kHplDger,
    kHplBcast,
    kHplDlaswp00N,
    kHplDtrsm,
    kHplDgemm,
    kHplNone
};

struct FunctionParam{
    int cmdSerialNum;
    HplFunction function;
    HPL_T_panel* panelInfo;
    int m;
    int n;
    int i;
    int j;
    int lda;
    int ldl2;
    double* workSpace;
    double* curA;
    double* nxtA;
    int ipiv;
    double divNum;
};

class Utility {
    public:
    static void pushToMxuCmdQ(std::shared_ptr<FunctionParam> cmd);
    static void popFromMxuCmdQ(std::shared_ptr<FunctionParam> cmd);
    static void pushToCpuCmdQ(std::shared_ptr<FunctionParam> cmd);
    static void popFromCpuCmdQ(std::shared_ptr<FunctionParam> cmd);
    static bool isMxuCmdQValid();
    static bool isCpuCmdQValid();
    static bool isMxuCmdQAvailable();
    static bool isCpuCmdQAvailable();
    static int getCmdSerialNum();
    static std::shared_ptr<FunctionParam> getFuncParam();

    static void fillAndPushDlocmax(HPL_T_panel*, int, int, int, double *);
    static void fillAndPushPdmxswp(HPL_T_panel*, int, int, int, double *);
    static void fillAndPushDlocswpN(HPL_T_panel*, int, int, double *);
    static void fillAndPushDscal(int, double, double *);
    static void fillAndPushDaxpy(int, double, double *, double *);
    static void fillAndPushDger(int, int, double *, double *, double *, int);
    static void fillAndPushBcast(HPL_T_panel*);
    static void fillAndPushDlaswp00N(int, int, double *, int, const int *);
    static void fillAndPushDtrsm(int, int, double *, double *, int);
    static void fillAndPushDgemm(int, int, int, double *, int, double *, int, double *);
    static void fillAndPushNone();

    private:
    Utility(){};
    static vector<std::shared_ptr<FunctionParam>> mxuCmdQueue;
    static vector<std::shared_ptr<FunctionParam>> cpuCmdQueue;
    static int cmdSerialNum;
};
#endif
