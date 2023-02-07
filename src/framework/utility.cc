#include "utility.h"

vector<FunctionParam> Utility::mxuCmdQueue;
vector<FunctionParam> Utility::cpuCmdQueue;
int Utility::cmdSerialNum = 0;


void Utility::pushToMxuCmdQ(FunctionParam cmd) {
    mxuCmdQueue.push_back(cmd);
}

void Utility::popFromMxuCmdQ(FunctionParam cmd) {}

void Utility::pushToCpuCmdQ(FunctionParam cmd) {}

void Utility::popFromCpuCmdQ(FunctionParam cmd) {}

int Utility::getCmdSerialNum() {
    return cmdSerialNum;
}

std::shared_ptr<FunctionParam> Utility::getFreeFuncParam() {
    std::shared_ptr<FunctionParam> ptr = std::make_shared<FunctionParam>();
    return ptr;
}
