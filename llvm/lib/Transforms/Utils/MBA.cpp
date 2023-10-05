//===-- HelloWorld.cpp - Example Transformations --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/Transforms/Utils/MBA.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

PreservedAnalyses MBAPass::run(Function &F, FunctionAnalysisManager &AM) {
  for (auto B = F.begin(), BE = F.end(); B != BE; ++B) {
    for (auto I = B->begin(), IE = B->end(); I != IE; ++I) {
      Instruction &Inst = *I;
      auto *BinOp = dyn_cast<BinaryOperator>(&Inst);
      if (!BinOp)
        continue;
      unsigned Opcode = BinOp->getOpcode();
      if (Opcode != Instruction::Add || !BinOp->getType()->isIntegerTy())
        continue;

      IRBuilder<> Builder(BinOp);
      Value *newVal = Builder.CreateAdd(
          Builder.CreateXor(BinOp->getOperand(0), BinOp->getOperand(1)),
          Builder.CreateMul(
              ConstantInt::get(BinOp->getType(), 2),
              Builder.CreateAnd(BinOp->getOperand(0), BinOp->getOperand(1))));
      Inst.replaceAllUsesWith(newVal);
    }
  }

  return PreservedAnalyses::all();
}
