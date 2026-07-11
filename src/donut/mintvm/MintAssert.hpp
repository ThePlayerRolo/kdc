#ifndef DONUT_MINTVM_MINT_ASSERT_HPP
#define DONUT_MINTVM_MINT_ASSERT_HPP

#include <types.h>

#define MINT_ASSERT_MESSAGE_FILELINE(file_, line_, expr_, ...) ((void)((expr_) || (::mintvm::MintSystemCall::panic  (file_, line_, __VA_ARGS__), 0)))
#define MINT_ASSERT_MESSAGE_LINE(line_, expr_, ...) MINT_ASSERT_MESSAGE_FILELINE(__FILE__, line_, expr_, __VA_ARGS__)

#define MINT_ASSERT_FAIL_FILELINE(file_, line_, expr_) MINT_ASSERT_MESSAGE_FILELINE(file_, line_, expr_, "Assertion failed.\n")
#define MINT_ASSERT_FAIL_LINE(line_, expr_) MINT_ASSERT_MESSAGE_LINE(line_, expr_, "Assertion failed.\n")

// To prevent not found errors in headers and prevent preamble
namespace mintvm { namespace MintSystemCall {
    DECL_WEAK extern void panic(const char* pFile, int line, const char* pMsg, ...);
}}

#endif
