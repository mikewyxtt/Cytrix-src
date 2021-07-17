//===--- Cytrix.h - Cytrix ToolChain Implementations ----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CYTRIX_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CYTRIX_H

#include "Gnu.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/ToolChain.h"

namespace clang {
namespace driver {
namespace toolchains {

class LLVM_LIBRARY_VISIBILITY Cytrix : public Generic_ELF {
public:
  Cytrix(const Driver &D, const llvm::Triple &Triple,
          const llvm::opt::ArgList &Args);
  bool HasNativeLLVMSupport() const override;

  CXXStdlibType GetDefaultCXXStdlibType() const override {
    return ToolChain::CST_Libcxx;
  }
  void addLibCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                             llvm::opt::ArgStringList &CC1Args) const override;
  void
  addLibStdCxxIncludePaths(const llvm::opt::ArgList &DriverArgs,
                           llvm::opt::ArgStringList &CC1Args) const override;
  void AddCXXStdlibLibArgs(const llvm::opt::ArgList &Args,
                           llvm::opt::ArgStringList &CmdArgs) const override;
  // Until dtrace (via CTF) and LLDB can deal with distributed debug info,
  // Cytrix defaults to standalone/full debug info.
  bool GetDefaultStandaloneDebug() const override { return true; }
  void
  addClangTargetOptions(const llvm::opt::ArgList &DriverArgs,
                        llvm::opt::ArgStringList &CC1Args,
                        Action::OffloadKind DeviceOffloadKind) const override;

protected:
  Tool *buildAssembler() const override;
  Tool *buildLinker() const override;
};

} // end namespace toolchains
} // end namespace driver
} // end namespace clang

#endif // LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_CYTRIX_H
