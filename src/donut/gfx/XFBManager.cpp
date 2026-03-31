#pragma peephole off
#include <donut/mem/Memory.hpp>
#include <donut/gfx/XFBManager.hpp>
#include <revolution/VI.h>

using gfx::XFBManager;

//TODO: Does HeapExp inherit IAllocator?
//This can't be a member or virtual or anything
//Its just pure mem2FixHeap
XFBManager::XFBManager(const gfx::VISetting& rVISetting)
    : m_0(rVISetting.fbSize(), 0x20, *(mem::IAllocator*)&mem::Memory::Instance->mem2FixHeap())
    , m_C(rVISetting.fbSize(), 0x20, *(mem::IAllocator*)&mem::Memory::Instance->mem2FixHeap())
    , m_18(false)

{
    VISetNextFrameBuffer(drawTargetXFB());
    VIWaitForRetrace();
    changeDrawTargetXFB();
}

void* XFBManager::drawTargetXFB() {
    if (m_18) {
        return m_0.block().startAddress();
    }

    return m_C.block().startAddress();
}

void XFBManager::changeDrawTargetXFB() {
    m_18 = m_18 == false;
}

void* XFBManager::target1() {
    return m_0.block().startAddress();
}

void* XFBManager::target2() {
    return m_C.block().startAddress();
}
