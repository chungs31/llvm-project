#include "llvm/Pass.h"
#include "llvm/IR/Function.h"

using namespace llvm;


MBA(): BasicBlockPass(ID) {}
bool runOnBasicBlock(BasicBlock &BB) override {
    bool modified = false;
    return modified;
}
}

static RegisterPass<MBA>
X("mba" , // the option name -> - mba
" Mixed Boolean Arithmetic Substitution " , // option description
true , // true as we don ’t modify the CFG
false // true if we ’ re writing an analysis
);

