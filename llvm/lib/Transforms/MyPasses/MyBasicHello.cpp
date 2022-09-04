//===- MyBasicHello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "mybasichello"

STATISTIC(MyBasicHelloCounter, "Counts number of functions greeted");
static int counter = 0;

namespace {
  // MyBasicHello - The first implementation, without getAnalysisUsage.
  struct MyBasicHello : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    MyBasicHello() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      ++MyBasicHelloCounter; counter++;
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << " " << counter <<'\n';
      return false;
    }
  };
}

char MyBasicHello::ID = 0;
static RegisterPass<MyBasicHello> X("mybasichello", "Hello World Pass");
