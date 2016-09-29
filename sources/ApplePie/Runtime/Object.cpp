#include "Object.hpp"
#include <ApplePie/Runtime/Class.hpp>

namespace ApplePie
{
Object::Object () :
    type_ (0),
    members_ ()
{

}

Object::~Object()
{

}

Object *Object::Call (unsigned functionName, std::vector<Object *> arguments)
{
    type_->CallObjectFunction (this, functionName, arguments);
}

Object *Object::Get (unsigned memberName)
{
    return members_ [memberName];
}

bool Object::IsIntanceOf (Class *baseClass)
{
    if (type_ == baseClass)
        return true;
    else
        return type_->IsInheritFrom (baseClass);
}
}
