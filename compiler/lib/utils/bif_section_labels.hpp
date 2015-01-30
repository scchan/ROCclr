//
// Copyright (c) 2012 Advanced Micro Devices, Inc. All rights reserved.
//
#ifndef _CL_UTILS_BIF_SECTION_LABELS_HPP_
#define _CL_UTILS_BIF_SECTION_LABELS_HPP_
#ifdef __cplusplus
extern "C" {
#endif
#define PRE 0
#define POST 1

typedef enum {
  symOpenclCompilerOptions,
  symAMDILCompilerOptions,
  symHSACompilerOptions,
  symOpenclLinkerOptions,
  symOpenclMeta,
  symOpenclKernel,
  symOpenclStub,
  symOpenclGlobal,
  symISAMeta,
  symISABinary,
  symAMDILText,
  symAMDILBinary,
  symHSAILText,
  symHSABinary,
  symAMDILFMeta,
  symISAText,
  symBRIGOperands,
  symBRIGxxxx,
  symBRIGStrtab,
  symX86Barrier,
  symAMDILHeader,
  symDebugInfo,
  symDebugilText,
  symDebugilBinary,
  symAsmText,
  symDLL,
  symLast,
  symKernelStats,
  symBRIGLoaderMap
} oclBIFSymbolID;

struct oclBIFSymbolStruct {
  oclBIFSymbolID id;
  // pre/post fix of the symbol string
  const char* str[2];
  // the BIF section that the symbol is stored for GPU/CPU
  aclSections sections[2];
};

// These are the symbols that are defined by the BIF 3.0 spec
static const oclBIFSymbolStruct BIF30[28] =
{
  // 0: BIF 3.0 compiler options, .comment section via library support.
  {symOpenclCompilerOptions,
   { "__OpenCL_", "compiler_options" }, {aclCOMMENT, aclCOMMENT}},
  // 1: BIF 3.0 AMDIL compile options, .comment section via -fbin-amdil.
  {symAMDILCompilerOptions,
   { "__AMDIL_", "_compiler_options" }, {aclCOMMENT, aclLAST}},
  // 2: BIF 3.0 HSAIL compile options, .comment section via -fbin-hsail.
  {symHSACompilerOptions,
   { "__HSAIL_", "_compiler_options" }, {aclCOMMENT, aclLAST}},
  // 3: BIF 3.0 linker options, .comment section via library support.
  {symOpenclLinkerOptions,
   { "__OpenCL_", "linker_options" }, {aclCOMMENT, aclCOMMENT}},
  // 4: BIF 3.0 per kernel metadata, .cg section via -fbin-cg for CPU,
  // .rodata section via -fbin-exe for GPU
  {symOpenclMeta, { "__OpenCL_", "_metadata" }, {aclRODATA, aclCODEGEN}},
  // 5: BIF 3.0 per kernel text(x86 only), .cg section via -fbin-cg.
  {symOpenclKernel, { "__OpenCL_", "_kernel" }, {aclLAST, aclCODEGEN}},
  // 6: BIF 3.0 per kernel stub(x86 only), .cg section via -fbin-cg.
  {symOpenclStub, { "__OpenCL_", "_stub" }, {aclLAST, aclCODEGEN}},
  // 7: BIF 3.0 per constant buffer data, .rodata section via -fbin-exe.
  {symOpenclGlobal, { "__OpenCL_", "_global" }, {aclRODATA, aclRODATA}},
  // 8: BIF 3.0 per kernel ISA metadata, .rodata section via -fbin-exe.
  {symISAMeta, { "__ISA_",    "_metadata" }, {aclRODATA, aclLAST}},
  // 9: BIF 3.0 per kernel ISA, .text section via -fbin-exe.
  {symISABinary, { "__ISA_",    "_binary" }, {aclTEXT, aclLAST}},
  // 10: BIF 3.0 per kernel AMDIL source, .internal section via -fbin-amdil.
  {symAMDILText, { "__AMDIL_",  "_text" }, {aclINTERNAL, aclLAST}},
  // 11: BIF 3.0 per kernel AMDIL binary, .internal section via -fbin-amdil.
  {symAMDILBinary, { "__AMDIL_",  "_binary" }, {aclINTERNAL, aclLAST}},
  // 12: BIF 3.0 per kernel HSAIL source, .internal section via -fbin-hsail.
  {symHSAILText, { "__HSAIL_",  "_text" }, {aclCODEGEN, aclLAST}},
  // 13: BIF 3.0 per kernel HSAIL binary, .internal section via -fbin-hsail.
  {symHSABinary, { "__BRIG__code",  "" }, {aclBRIGcode, aclLAST}},
  // 14: BIF 3.0 per function metadata, .internal section via -fbin-amdil.
  {symAMDILFMeta, { "__AMDIL_",  "_fmetadata" }, {aclINTERNAL, aclLAST}},
  // 15: BIF 3.0 per kernel ISA text, .internal section via disassembly.
  {symISAText, { "__ISA_",    "_text" }, {aclINTERNAL, aclLAST}},
  // 16: BIF 3.0 BRIG operands declarations, .brig section via -fbin-brig.
  {symBRIGOperands, { "__BRIG__operands","" }, {aclBRIGoprs, aclLAST}},
  // 17: Unused after changes in HSAIL PRM
  {symBRIGxxxx, { "","" }, {aclLAST, aclLAST}},
  // 18: BIF 3.0 BRIG strtab declarations, .brig section via -fbin-brig.
  {symBRIGStrtab, { "__BRIG__strtab","" }, {aclBRIGstrs, aclLAST}},
  // 19: BIF 3.0 per kernel barrier metadata, only valid for X86.
  {symX86Barrier, { "__X86_", "_barrier" }, {aclLAST, aclLAST}},
  // 20: BIF 3.0 per kernel header, .internal section via -fbin-amdil.(Legacy from bif2.x)
  {symAMDILHeader, { "__AMDIL_",  "_header"}, {aclINTERNAL, aclLAST}},
  // 21: BIF 3.0 HSA BRIG or ISA debug info
  {symDebugInfo, { "__debug_brig__","__debug_isa__"}, {aclHSADEBUG, aclLAST}},
  // 22: BIF 3.0 debugil text, .internal section via -g
  {symDebugilText, { "__debugil_text", "" }, {aclINTERNAL, aclLAST}},
  // 23: BIF 3.0 debugil binary, .internal section, can be converted from
  // __debugil_text
  {symDebugilBinary, { "__debugil_binary", "" }, {aclINTERNAL, aclLAST}},
  {symAsmText, {"", ""}, {aclLAST, aclCODEGEN}},
  {symDLL, {"", ""}, {aclLAST, aclTEXT}},
  // 26: BIF 3.0 HSAIL kernel statistics
  {symKernelStats, { "__HSAIL_", "_kernel_statistics" }, {aclKSTATS, aclLAST}},
  // 27: BIF 3.0 BRIG loader map
  {symBRIGLoaderMap, { "__Loader_Map", "" }, {aclCODEGEN, aclLAST}},
}; // BIF30


// These are the sections that are defined by the BIF 2.0 spec
static const oclBIFSymbolStruct BIF20[13] =
{
  {symOpenclCompilerOptions,
   { "__OpenCL_compile_options", "" }, {aclCOMMENT, aclCOMMENT}},
  {symOpenclLinkerOptions,
   { "__OpenCL_linker_options", "" }, {aclCOMMENT, aclCOMMENT}},
  {symOpenclKernel, { "__OpenCL_", "_kernel" }, {aclLAST, aclDLL}},
  {symISABinary, { "__OpenCL_", "_kernel" }, {aclCAL, aclLAST}},
  {symOpenclMeta, { "__OpenCL_", "_metadata" }, {aclRODATA, aclDLL}},
  {symAMDILHeader, { "__OpenCL_", "_header" }, {aclRODATA, aclLAST}},
  {symOpenclGlobal, { "__OpenCL_", "_global" }, {aclRODATA, aclLAST}},
  {symAMDILText, { "__OpenCL_", "_amdil" }, {aclILTEXT, aclLAST}},
  {symAMDILFMeta, { "__OpenCL_", "_fmetadata" }, {aclRODATA, aclLAST}},
  {symOpenclStub, { "__OpenCL_", "_stub" }, {aclLAST, aclDLL}},
  {symDebugilText, {"", ""}, {aclILDEBUG, aclLAST}},
  {symAsmText, {"", ""}, {aclLAST, aclASTEXT}},
  {symDLL, {"", ""}, {aclLAST, aclDLL}},
}; // BIF20


inline const oclBIFSymbolStruct* findBIFSymbolStruct(
  const oclBIFSymbolStruct* symbols, size_t nSymbols, oclBIFSymbolID id)
{
  for (size_t i = 0; i < nSymbols; ++i) {
    if (id == symbols[i].id) {
      return &symbols[i];
    }
  }
  return NULL;
}

inline const oclBIFSymbolStruct* findBIF30SymStruct(oclBIFSymbolID id)
{
  size_t nBIF30Symbol = sizeof(BIF30)/sizeof(oclBIFSymbolStruct);
  return findBIFSymbolStruct(BIF30, nBIF30Symbol, id);
}

#ifdef __cplusplus
}
#endif
#endif // _CL_UTILS_BIF_SECTION_LABELS_HPP_
