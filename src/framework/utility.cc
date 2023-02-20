#include "utility.h"


vector<std::shared_ptr<FunctionParam>> Utility::mxuCmdQueue;
vector<std::shared_ptr<FunctionParam>> Utility::cpuCmdQueue;
int Utility::cmdSerialNum = 0;
int64_t Utility::opNum = 0;
int64_t Utility::bwInBytes = 0;


void Utility::pushToMxuCmdQ(std::shared_ptr<FunctionParam> cmd) {
    mxuCmdQueue.push_back(cmd);
}

void Utility::popFromMxuCmdQ(std::shared_ptr<FunctionParam> cmd) {}

void Utility::pushToCpuCmdQ(std::shared_ptr<FunctionParam> cmd) {}

void Utility::popFromCpuCmdQ(std::shared_ptr<FunctionParam> cmd) {}

int Utility::getCmdSerialNum() {
    cmdSerialNum++;
    // cout << "cmdSerialNum = " << cmdSerialNum << endl;
    return cmdSerialNum;
}

void Utility::printCmdNum() {
    cout << "cmdSerialNum = " << cmdSerialNum << endl;
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


void Utility::fillAndPushDlaswp00N(int _j, int _n, double * _curA, int _lda, int * _ipiv) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplDlaswp00N;
    tmpPtr->j = _j;
    tmpPtr->n = _n;
    tmpPtr->curA = _curA;
    tmpPtr->lda = _lda;
    tmpPtr->ipiv = _ipiv;
    pushToMxuCmdQ(tmpPtr);
}


void Utility::fillAndPushProcessIpiv(int* _ipiv, double* _dpiv, int _jb, int _iroff) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kProccessIpiv;
    tmpPtr->ipiv = _ipiv;
    tmpPtr->dpiv = _dpiv;
    tmpPtr->j = _jb;
    tmpPtr->i = _iroff;
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


void Utility::fillAndPushBinit(HPL_T_panel* _panel) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHPLBinit;
    tmpPtr->panelInfo = _panel;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushBwait(HPL_T_panel* _panel) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHPLBwait;
    tmpPtr->panelInfo = _panel;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushEditPanel(HPL_T_panel* _panel, double * _work, int _n) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kEditPanel;
    tmpPtr->panelInfo = _panel;
    tmpPtr->workSpace = _work;
    tmpPtr->n = _n;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushEditPanelAfterPF(HPL_T_panel* _panel, int _jb) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kEditPanelAfterPF;
    tmpPtr->panelInfo = _panel;
    tmpPtr->j = _jb;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushEditPanelBeforePF(HPL_T_panel* _panel, int _jb) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kEditPanelBeforePF;
    tmpPtr->panelInfo = _panel;
    tmpPtr->j = _jb;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushPanelInit(HPL_T_panel _initPanel, HPL_T_panel* _panel) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplPanelInit;
    tmpPtr->panelInfo = _panel;
    tmpPtr->initPanel = _initPanel;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::fillAndPushPanelFree(HPL_T_panel* _panel) {
    std::shared_ptr<FunctionParam> tmpPtr = Utility::getFuncParam();
    tmpPtr->cmdSerialNum = Utility::getCmdSerialNum();
    tmpPtr->function = kHplPanelFree;
    tmpPtr->panelInfo = _panel;
    pushToMxuCmdQ(tmpPtr);
}

void Utility::replay() {
    int flag;
    while(mxuCmdQueue.size() != 0) {
        std::shared_ptr<FunctionParam> tmpFuncPtr = mxuCmdQueue.front();
        // std::cout << tmpFuncPtr->cmdSerialNum << std::endl;
        switch(tmpFuncPtr->function) {
            case kHplDlocmax:
                HPL_dlocmax( tmpFuncPtr->panelInfo, tmpFuncPtr->m, tmpFuncPtr->i, tmpFuncPtr->j, tmpFuncPtr->workSpace);
                break;
            case kHplPdmxswp:
                HPL_pdmxswp( tmpFuncPtr->panelInfo, tmpFuncPtr->m, tmpFuncPtr->i, tmpFuncPtr->j, tmpFuncPtr->workSpace);
                break;
            case kHplDlocswpN:
                HPL_dlocswpN( tmpFuncPtr->panelInfo, tmpFuncPtr->i, tmpFuncPtr->j, tmpFuncPtr->workSpace);
                break;
            case kHplDscal:
                HPL_dscal( tmpFuncPtr->m, tmpFuncPtr->divNum, tmpFuncPtr->curA, 1 );
                break;
            case kHplDaxpy:
                HPL_daxpy( tmpFuncPtr->m, tmpFuncPtr->divNum, tmpFuncPtr->curA, 1, tmpFuncPtr->nxtA, 1 );
                break;
            case kHplDger:
                HPL_dger( CblasColMajor, tmpFuncPtr->m, tmpFuncPtr->n, -HPL_rone, tmpFuncPtr->curA, 1,
                        tmpFuncPtr->workSpace, 1, tmpFuncPtr->nxtA, tmpFuncPtr->lda );
                break;
            case kHplBcast:
                HPL_bcast( tmpFuncPtr->panelInfo, &flag );
                break;
            case kHplDlaswp00N:
                HPL_dlaswp00N( tmpFuncPtr->j, tmpFuncPtr->n, tmpFuncPtr->curA, tmpFuncPtr->lda, tmpFuncPtr->ipiv);
                break;
            case kHplDtrsm:
                HPL_dtrsm( CblasColMajor, CblasLeft, CblasLower, CblasNoTrans,
                        CblasUnit, tmpFuncPtr->j, tmpFuncPtr->n, HPL_rone, tmpFuncPtr->workSpace, tmpFuncPtr->j, tmpFuncPtr->curA, tmpFuncPtr->lda );
                break;
            case kHplDgemm:
                HPL_dgemm( CblasColMajor, CblasNoTrans, CblasNoTrans, tmpFuncPtr->m, tmpFuncPtr->n,
                        tmpFuncPtr->j, -HPL_rone, tmpFuncPtr->workSpace, tmpFuncPtr->ldl2, tmpFuncPtr->curA, tmpFuncPtr->lda, HPL_rone,
                        tmpFuncPtr->nxtA, tmpFuncPtr->lda );
                break;
            case kHPLBinit:
                HPL_binit(tmpFuncPtr->panelInfo);
                break;
            case kHPLBwait:
                HPL_bwait(tmpFuncPtr->panelInfo);
                break;
            case kEditPanel:
                tmpFuncPtr->panelInfo->A = tmpFuncPtr->workSpace; tmpFuncPtr->panelInfo->nq -= tmpFuncPtr->n; tmpFuncPtr->panelInfo->jj += tmpFuncPtr->n;
                break;
            case kEditPanelAfterPF:
                tmpFuncPtr->panelInfo->A   = Mptr( tmpFuncPtr->panelInfo->A, 0, tmpFuncPtr->j, tmpFuncPtr->panelInfo->lda );
                tmpFuncPtr->panelInfo->nq -= tmpFuncPtr->j;
                tmpFuncPtr->panelInfo->jj += tmpFuncPtr->j;
                break;
            case kEditPanelBeforePF:
                tmpFuncPtr->panelInfo->n -= tmpFuncPtr->j;
                tmpFuncPtr->panelInfo->ja += tmpFuncPtr->j;
                break;
            case kProccessIpiv:
                for(int i = 0; i < tmpFuncPtr->j; i++ ) { tmpFuncPtr->ipiv[i] = (int)(tmpFuncPtr->dpiv[i]) - tmpFuncPtr->i; }
                break;
            case kHplPanelInit:
                HPL_pdpanel_init( tmpFuncPtr->initPanel.grid, tmpFuncPtr->initPanel.algo, tmpFuncPtr->initPanel.n, tmpFuncPtr->initPanel.n+1, tmpFuncPtr->initPanel.jb,
                tmpFuncPtr->initPanel.pmat, tmpFuncPtr->initPanel.ja, tmpFuncPtr->initPanel.ja, tmpFuncPtr->initPanel.jj, tmpFuncPtr->panelInfo );
                break;
            case kHplPanelFree:
                HPL_pdpanel_free(tmpFuncPtr->panelInfo);
                break;
            case kHplNone:
                std::cout << "GGWP" << std::endl;
                break;
            default:
                std::cout << "GGWP" << std::endl;
                break;
        }
        calculatePerf(tmpFuncPtr);
        mxuCmdQueue.erase(mxuCmdQueue.begin());
    }
}


void Utility::printProfileInfo() {
    cout << "TotalOpNum = " << opNum << endl;
    cout << "TotalBwInBytes = " << bwInBytes << endl;
}

void Utility::calculatePerf(std::shared_ptr<FunctionParam> curFuncPtr) {
    int remainM, remainN, nb;
    const int kAlign64Byte = 64;//This is per transaction width
    const int kNumByteOf1Ele = 8;
    int modeNumN, modeNumM;
    int totalComByteCnt = 0;
    int totalOpNum = 0;
    // Assume column major
    //         N
    //  ________________
    // |
    // |
    // | M
    switch(curFuncPtr->function) {
            case kHplDlocmax:
                remainM = curFuncPtr->m * kNumByteOf1Ele;
                modeNumM = remainM % kAlign64Byte;
                totalComByteCnt += modeNumM ? remainM - modeNumM + 2 * kAlign64Byte : remainM;
                totalOpNum += curFuncPtr->m;
                break;
            case kHplPdmxswp:
                //swap 2 column w/ nb size
                remainM = curFuncPtr->panelInfo->nb;
                totalComByteCnt += remainM * kAlign64Byte * 4; //2Read / 2write
                break;
            case kHplDlocswpN:
                //calculate in kHplPdmxswp
                break;
            case kHplDscal:
                remainM = curFuncPtr->m * kNumByteOf1Ele;
                modeNumM = remainM % kAlign64Byte;
                totalComByteCnt += modeNumM ? (remainM - modeNumM + 2 * kAlign64Byte) * 2 : remainM * 2;//R/W
                totalOpNum += (curFuncPtr->m - 1);
                break;
            case kHplDaxpy:
                remainM = curFuncPtr->m * kNumByteOf1Ele;
                modeNumM = remainM % kAlign64Byte;
                totalComByteCnt += modeNumM ? (remainM - modeNumM + 2 * kAlign64Byte) * 3 : remainM * 3; // 2R 1W
                totalOpNum += 2 * curFuncPtr->m; //a * x + y
                break;
            case kHplDger:
                //A = -X * Y^T + A
                remainM = curFuncPtr->m * kNumByteOf1Ele;
                modeNumM = remainM % kAlign64Byte;
                remainN = curFuncPtr->n;
                totalComByteCnt += modeNumM ? remainM - modeNumM + 2 * kAlign64Byte : remainM; //load X
                totalComByteCnt += remainN * kAlign64Byte; //load Y
                totalComByteCnt += modeNumM ? remainN * (remainM - modeNumM + 2 * kAlign64Byte) * 2 : remainN * remainM * 2; // 1R 1W A
                totalOpNum += curFuncPtr->m * curFuncPtr->n * 2;
                break;
            case kHplDlaswp00N:
                //Swap 2 column w/ remain n size
                remainN = curFuncPtr->n * kAlign64Byte;
                nb = curFuncPtr->j;
                totalComByteCnt += remainN * nb * 4; //2Read + 2Write
                break;
            case kHplDtrsm:
                //Solve upper triangle
                remainN = curFuncPtr->n * kAlign64Byte;
                nb = curFuncPtr->j;
                totalComByteCnt += remainN * nb * 2; //R/W
                totalOpNum += curFuncPtr->n * (1 + nb - 1) * (nb - 1) / 2 * 2;
                break;
            case kHplDgemm:
                remainN = curFuncPtr->n * kNumByteOf1Ele;
                remainM = curFuncPtr->m * kNumByteOf1Ele;
                nb = curFuncPtr->j;
                modeNumN = remainN % kAlign64Byte;
                modeNumM = remainM % kAlign64Byte;
                totalComByteCnt += remainM ? 2 * curFuncPtr->n * (remainM - modeNumN + 2 * kAlign64Byte) : 2 * curFuncPtr->n * remainM; //R/W update matrix
                totalComByteCnt += remainM ? nb * (remainM - modeNumN + 2 * kAlign64Byte) : nb * remainM; //R left matrix
                totalComByteCnt += curFuncPtr->n * kAlign64Byte;// R up matrix
                totalOpNum += curFuncPtr->m * curFuncPtr->n * nb * 2 + curFuncPtr->m * curFuncPtr->n;
                break;
            default:
                // std::cout << "GGWP" << std::endl;
                break;
    }
    bwInBytes += totalComByteCnt;
    opNum += totalOpNum;
    //2/3 n^3 + n^2
}
