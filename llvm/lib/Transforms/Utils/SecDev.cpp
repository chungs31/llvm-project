
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Utils/SecPass.h"

using namespace llvm;

namespace llvm {

void checkMemory(void *ptr) {
    llvm::outs() << ptr << "\n";
}

static void visitStoreInst(StoreInst *inst) {  
Value *ptr = inst->getPointerOperand();
  if (isa<GlobalValue>(ptr))
    return;
  if (isa<AllocaInst>(ptr))
    return;
  LLVMContext &C = inst->getContext();
  ptr = new BitCastInst(ptr, PointerType::getVoidTy(C), ptr->getName(), inst);
  CallInst::Create(checkMemory, ArrayRef<Value *>(ptr), "", inst);
}

PreservedAnalyses SecPass::run(Module &M, ModuleAnalysisManager &AM) {
  for (auto F = M.begin(); F != M.end(); ++F) {
    for (auto B = F->begin(); B != F->end(); ++B) {
      for (auto I = B->begin(); I != B->end(); ++I) {
        Instruction &inst = *I;
        llvm::outs() << inst.getName() << "\n";
        if (StoreInst *SI = dyn_cast<StoreInst>(&inst)) {
            visitStoreInst(SI);
        }
      }
    }
  }
  return PreservedAnalyses::none();
}



} // namespace llvm