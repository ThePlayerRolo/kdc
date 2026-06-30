#pragma peephole off
#include <donut/mem/DataBlock.hpp>
#include <donut/mem/IAllocator.hpp>

using mem::DataBlock;

DataBlock::DataBlock(u32 size, s32 align, IAllocator& rAllocator)
    : mAllocator(&rAllocator)
    , mBlock(rAllocator.allocatorAlloc(size, align), size)
{}

DataBlock::~DataBlock() {
    mAllocator->allocatorFree(mBlock.mStartAddress);
}
