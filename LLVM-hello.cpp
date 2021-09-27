// g++ LLVM-hello.cpp `llvm-config-10 --cxxflags --ldflags --libs`

#include "llvm-10/llvm/Support/raw_ostream.h"
#include "llvm-10/llvm/IR/LLVMContext.h"
#include "llvm-10/llvm/IR/Module.h"
#include "llvm-10/llvm/IR/IRBuilder.h"
#include "llvm-10/llvm/ExecutionEngine/ExecutionEngine.h"
#include <llvm-10/llvm/ExecutionEngine/GenericValue.h>

int main() {
    llvm::LLVMContext context;
    return 0;
}