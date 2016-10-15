#pragma once
#include <string>
#include <vector>
#include <Dwarf/Runtime/Object.hpp>

namespace Dwarf
{
class Class : public StringifyAble, public ObjectWithKnownType
{
friend class Object;
protected:
    virtual Object *CallObjectFunction (Object *object, unsigned functionName, std::vector <Object *> arguments) = 0;
    std::map <unsigned, Object *> *GetMembersMap (Object *object);
    void SetThisAsObjectType (Object *object);
public:
    Class ();
    virtual ~Class ();

    virtual bool CreateInstance (Object *toObject) = 0;
    virtual bool IsInheritFrom (Class *baseClass) = 0;
};
}
