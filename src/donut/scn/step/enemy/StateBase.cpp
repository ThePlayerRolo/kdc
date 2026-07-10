#pragma peephole off
#include "scn/step/enemy/StateBase.hpp"

namespace scn { namespace step { namespace enemy {
    StateBase::StateBase(Enemy* pObj) : mObj(*pObj) { }
    void StateBase::procAnim() { }
    void StateBase::procMove() { }
    void StateBase::procConstraint() { }
    void StateBase::procFixPos() { }
    void StateBase::procObjCollReact() { }
    StateBase::~StateBase() { }
    //NOTE: All functions below are code merged into others. Refer to the header for more details
    Enemy& StateBase::obj() const { return mObj; }
    Enemy& StateBase::obj() { return mObj; }
    Enemy* StateBase::objPtr() { return &mObj; }
}}}
