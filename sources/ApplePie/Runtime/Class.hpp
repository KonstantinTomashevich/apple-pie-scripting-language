#pragma once
#include <string>
#include <vector>

#include <ApplePie/Runtime/Object.hpp>
#include <ApplePie/AST/Declarations.hpp>

namespace ApplePie
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

    virtual std::vector <VariableDeclaration *> GetMembersDeclaritions () = 0;
    virtual std::vector <FunctionDeclarition *> GetFunctionsDeclaritions () = 0;
    virtual bool CreateInstance (Object *toObject) = 0;
    virtual bool IsInheritFrom (Class *baseClass) = 0;
};
}
