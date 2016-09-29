#pragma once
#include <string>
#include <vector>
#include <map>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
class Class;
class Object : public StringifyAble, public ObjectWithKnownType, public RefCounted
{
friend class Class;
protected:
    Class *type_;
    std::map <unsigned, Object *> members_;
public:
    Object ();
    virtual ~Object ();

    Object *Call (unsigned functionName, std::vector <Object *> arguments);
    Object *Get (unsigned memberName);
    bool IsIntanceOf (Class *baseClass);
};
}
