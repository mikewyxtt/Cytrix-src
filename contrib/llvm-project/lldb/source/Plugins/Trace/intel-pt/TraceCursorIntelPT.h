//===-- TraceCursorIntelPT.h ------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SOURCE_PLUGINS_TRACE_INTEL_PT_TRACECURSORINTELPT_H
#define LLDB_SOURCE_PLUGINS_TRACE_INTEL_PT_TRACECURSORINTELPT_H

#include "IntelPTDecoder.h"
#include "TraceIntelPTSessionFileParser.h"

namespace lldb_private {
namespace trace_intel_pt {

class TraceCursorIntelPT : public TraceCursor {
public:
  TraceCursorIntelPT(lldb::ThreadSP thread_sp,
                     DecodedThreadSP decoded_thread_sp);

  size_t Seek(int64_t offset, SeekType origin) override;

  virtual bool Next() override;

  llvm::Error GetError() override;

  lldb::addr_t GetLoadAddress() override;

  lldb::TraceInstructionControlFlowType
  GetInstructionControlFlowType() override;

  bool IsError() override;

private:
  size_t GetInternalInstructionSize();

  /// Storage of the actual instructions
  DecodedThreadSP m_decoded_thread_sp;
  /// Internal instruction index currently pointing at.
  size_t m_pos;
};

} // namespace trace_intel_pt
} // namespace lldb_private

#endif // LLDB_SOURCE_PLUGINS_TRACE_INTEL_PT_TRACECURSORINTELPT_H