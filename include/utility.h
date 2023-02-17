#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <vector>
#include <memory>

#include "hpl.h"

using namespace std;

enum HplFunction
{
    kHplNone = 0,
    kHplDlocmax,
    kHplPdmxswp,
    kHplDlocswpN,
    kHplDscal,
    kHplDaxpy,
    kHplDger,
    kHplDlaswp00N,
    kHplDtrsm,
    kHplDgemm,
    kHplPanelInit,
    kHplPanelFree,
    kHPLPdpanelFree,
    kHPLPdpanelInit,
    kHPLBinit,
    kHPLBwait,
    kHplBcast,
    kEditPanel,
    kEditPanelAfterPF,
    kEditPanelBeforePF,
    kProccessIpiv
};

struct FunctionParam{
    int cmdSerialNum;
    HplFunction function;
    HPL_T_panel* panelInfo;
    HPL_T_panel initPanel;
    int m;
    int n;
    int i;
    int j;
    int lda;
    int ldl2;
    double* workSpace;
    double* curA;
    double* nxtA;
    double* dpiv;
    int* ipiv;
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
    static void fillAndPushDlaswp00N(int, int, double *, int, int *);
    static void fillAndPushDtrsm(int, int, double *, double *, int);
    static void fillAndPushDgemm(int, int, int, double *, int, double *, int, double *);
    static void fillAndPushNone();
    static void fillAndPushPdpanelFree(HPL_T_panel*);
    static void fillAndPushBinit(HPL_T_panel*);
    static void fillAndPushBwait(HPL_T_panel*);
    static void fillAndPushEditPanel(HPL_T_panel*,double *, int);
    static void fillAndPushEditPanelAfterPF(HPL_T_panel*, int);
    static void fillAndPushEditPanelBeforePF(HPL_T_panel*, int);
    static void fillAndPushProcessIpiv(int*, double*, int, int);
    static void fillAndPushPanelInit(HPL_T_panel, HPL_T_panel*);
    static void fillAndPushPanelFree(HPL_T_panel*);

    static void replay();
    static void printCmdNum();
    static void printProfileInfo();

    private:
    Utility(){};
    static vector<std::shared_ptr<FunctionParam>> mxuCmdQueue;
    static vector<std::shared_ptr<FunctionParam>> cpuCmdQueue;
    static int cmdSerialNum;
    static int64_t opNum;
    static int64_t bwInBytes;
    static void calculatePerf(std::shared_ptr<FunctionParam>);
};
#endif
