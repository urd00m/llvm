#define DEBUG_TYPE "opCounter"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/SymbolTableListTraits.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Instruction.h"

using namespace llvm;

namespace {
  struct OpPrinter : public FunctionPass {
    static char ID;
    OpPrinter() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
      errs() << "Function: " << F.getName() << "\n";
      for (Function::iterator bb = F.begin(), e = F.end(); bb != e; ++bb) {
	for (BasicBlock::iterator i = bb->begin(), e = bb->end(); i != e; ++i) {
	  errs() << "Opcode: " << i->getOpcodeName() << "\n";
	}
      }
      return false; 
    }

    /*
    virtual bool runOnFunction(Function &F) {
      errs() << "Function: " << F.getName() << "\n\n";
      
      SymbolTableList<BasicBlock> block_table = F.getBasicBlockList();

      for(BasicBlock bb : block_table) {
	errs() << bb.front().getOpcode() << "\n";
      }

      return false;
    }
    */

  };
}

char OpPrinter::ID = 0;
static RegisterPass<OpPrinter> X("opPrinter", "Prints out opcodes");
