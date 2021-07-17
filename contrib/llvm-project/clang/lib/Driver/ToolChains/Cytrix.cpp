//===--- Cytrix.cpp - Cytrix ToolChain Implementations --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Cytrix.h"
#include "Arch/ARM.h"
#include "Arch/Mips.h"
#include "Arch/Sparc.h"
#include "CommonArgs.h"
#include "clang/Driver/Compilation.h"
#include "clang/Driver/DriverDiagnostic.h"
#include "clang/Driver/Options.h"
#include "clang/Driver/SanitizerArgs.h"
#include "llvm/Option/ArgList.h"
#include "llvm/Support/VirtualFileSystem.h"

using namespace clang::driver;
using namespace clang::driver::tools;
using namespace clang::driver::toolchains;
using namespace clang;
using namespace llvm::opt;


/// Cytrix - Cytrix tool chain which can call as(1) and ld(1) directly.

Cytrix::Cytrix(const Driver &D, const llvm::Triple &Triple,
                 const ArgList &Args)
    : Generic_ELF(D, Triple, Args) {
      // commented until userspace is developed

      /*
  // When targeting 32-bit platforms, look for '/usr/lib32/crt1.o' and fall
  // back to '/usr/lib' if it doesn't exist.
  if ((Triple.getArch() == llvm::Triple::x86 || Triple.isMIPS32() ||
       Triple.isPPC32()) &&
      D.getVFS().exists(getDriver().SysRoot + "/usr/lib32/crt1.o"))
    getFilePaths().push_back(getDriver().SysRoot + "/usr/lib32");
  else
    getFilePaths().push_back(getDriver().SysRoot + "/usr/lib");

  */
}


void Cytrix::addLibCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                                    llvm::opt::ArgStringList &CC1Args) const {
  // commented until userspace is developed
  /*
  addSystemInclude(DriverArgs, CC1Args,
                   getDriver().SysRoot + "/usr/include/c++/v1");
  */
}

void Cytrix::addLibStdCxxIncludePaths(
    const llvm::opt::ArgList &DriverArgs,
    llvm::opt::ArgStringList &CC1Args) const {
  // commented until userspace is developed
  /*
  addLibStdCXXIncludePaths(getDriver().SysRoot + "/usr/include/c++/4.2", "", "",
                           DriverArgs, CC1Args);
  */
}

void Cytrix::AddCXXStdlibLibArgs(const ArgList &Args,
                                  ArgStringList &CmdArgs) const {
  // commented until userspace is developed
  /*
  CXXStdlibType Type = GetCXXStdlibType(Args);
  bool Profiling =
      Args.hasArg(options::OPT_pg) && getTriple().getOSMajorVersion() < 14;

  switch (Type) {
  case ToolChain::CST_Libcxx:
    CmdArgs.push_back(Profiling ? "-lc++_p" : "-lc++");
    break;

  case ToolChain::CST_Libstdcxx:
    CmdArgs.push_back(Profiling ? "-lstdc++_p" : "-lstdc++");
    break;
  }
  */
}


Tool *Cytrix::buildAssembler() const { return new tools::gnutools::Assembler(*this); }

Tool *Cytrix::buildLinker() const { return new tools::gnutools::Linker(*this); }


bool Cytrix::HasNativeLLVMSupport() const { return true; }

void Cytrix::addClangTargetOptions(const ArgList &DriverArgs,
                                    ArgStringList &CC1Args,
                                    Action::OffloadKind) const {
  // commented until userspace is developed
  /*
  if (!DriverArgs.hasFlag(options::OPT_fuse_init_array,
                          options::OPT_fno_use_init_array,
                          getTriple().getOSMajorVersion() >= 12))
    CC1Args.push_back("-fno-use-init-array");
  */
}
