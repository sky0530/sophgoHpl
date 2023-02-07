#include "utility.h"

vector<std::shared_ptr<FunctionParam>> Utility::mxuCmdQueue;
vector<std::shared_ptr<FunctionParam>> Utility::cpuCmdQueue;
int Utility::cmdSerialNum = 0;


void Utility::pushToMxuCmdQ(std::shared_ptr<FunctionParam> cmd) {
    mxuCmdQueue.push_back(cmd);
}

void Utility::popFromMxuCmdQ(std::shared_ptr<FunctionParam> cmd) {}

void Utility::pushToCpuCmdQ(std::shared_ptr<FunctionParam> cmd) {}

void Utility::popFromCpuCmdQ(std::shared_ptr<FunctionParam> cmd) {}

int Utility::getCmdSerialNum() {
    return cmdSerialNum;
}

std::shared_ptr<FunctionParam> Utility::getFuncParam() {
    std::shared_ptr<FunctionParam> ptr = std::make_shared<FunctionParam>();
    return ptr;
}

void Utility::fillAndPushDlocmax(HPL_T_panel* _panel, int _m, int _i, int _j, double * _work) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDlocmax;
    tmpPtr->panelInfo = _panel;
    tmpPtr->m = _m;
    tmpPtr->i = _i;
    tmpPtr->j = _j;
    tmpPtr->workSpace = _work;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushPdmxswp(HPL_T_panel* _panel, int _m, int _i, int _j, double * _work) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplPdmxswp;
    tmpPtr->panelInfo = _panel;
    tmpPtr->m = _m;
    tmpPtr->i = _i;
    tmpPtr->j = _j;
    tmpPtr->workSpace = _work;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushDlocswpN(HPL_T_panel* _panel, int _i, int _j, double * _work) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDlocswpN;
    tmpPtr->panelInfo = _panel;
    tmpPtr->i = _i;
    tmpPtr->j = _j;
    tmpPtr->workSpace = _work;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushDscal(int _m, double _divNum, double * _acur) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDscal;
    tmpPtr->m = _m;
    tmpPtr->divNum = _divNum;
    tmpPtr->curA = _acur;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushDaxpy(int _m, double _divNum, double * _acur, double * _anxt) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDaxpy;
    tmpPtr->m = _m;
    tmpPtr->divNum = _divNum;
    tmpPtr->curA = _acur;
    tmpPtr->nxtA = _anxt;
    pushToMxuCmdQ(tmpPtr);
}


void Utility::fillAndPushDger(int _m, int _n, double* _acur, double * _work, double * _anxt, int _lda) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDger;
    tmpPtr->m = _m;
    tmpPtr->n = _n;
    tmpPtr->curA = _acur;
    tmpPtr->nxtA = _anxt;
    tmpPtr->workSpace = _work;
    tmpPtr->lda = _lda;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushBcast(HPL_T_panel* _panel) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplBcast;
    tmpPtr->panelInfo = _panel;
    pushToMxuCmdQ(tmpPtr);
}


void Utility::fillAndPushDlaswp00N(int _j, int _n, double * _curA, int _lda, const int * _ipiv) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDlaswp00N;
    tmpPtr->j = _j;
    tmpPtr->n = _n;
    tmpPtr->curA = _curA;
    tmpPtr->lda = _lda;
    tmpPtr->ipiv = *_ipiv;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushDtrsm(int _j, int _n, double * _work, double * _curA, int _lda) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDtrsm;
    tmpPtr->j = _j;
    tmpPtr->n = _n;
    tmpPtr->workSpace = _work;
    tmpPtr->curA = _curA;
    tmpPtr->lda = _lda;
    pushToMxuCmdQ(tmpPtr);
}


void Utility::fillAndPushNone() {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplNone;
    pushToMxuCmdQ(tmpPtr);
}


void Utility::fillAndPushDgemm(int _m, int _n, int _j, double * _work, int _ldl2, double * _curA, int _lda, double * _nxtA) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDgemm;
    tmpPtr->m = _m;
    tmpPtr->n = _n;
    tmpPtr->j = _j;
    tmpPtr->workSpace = _work;
    tmpPtr->ldl2 = _ldl2;
    tmpPtr->curA = _curA;
    tmpPtr->lda = _lda;
    tmpPtr->nxtA = _nxtA;
    pushToMxuCmdQ(tmpPtr);
}
