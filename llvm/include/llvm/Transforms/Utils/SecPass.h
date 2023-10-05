//===-- MBA.h - Example Transformations ------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_SEC_UTILS_H
#define LLVM_SEC_UTILS_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class SecPass : public PassInfoMixin<SecPass> {
public:
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM);
};

} // namespace llvm

#endif // LLVM_SEC_UTILS_H
