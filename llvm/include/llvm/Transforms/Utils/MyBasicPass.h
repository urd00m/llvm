#ifndef LLVM_TRANSFORMS_BASICNEW_HELLOWORLD_H
#define LLVM_TRANSFORMS_BASICNEW_HELLOWORLD_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class MyBasicPass : public PassInfoMixin<MyBasicPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_HELLONEW_HELLOWORLD_H
