#pragma once
#include <string>
#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/Declarations/VariableDeclaration.hpp>

namespace Dwarf
{
const unsigned AST_VARIABLE_REFERENCE_TYPE_HASH = StringToHash ("AstVariableReference");

class AstVariableReference : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstVariableReference, AST_VARIABLE_REFERENCE_TYPE_HASH)
protected:
    // Provider is object, from which we trying to get variable.
    // If we getting variable from current execution context, provider is null. For example in "myVar" provider is null.
    // In case of "myVar.myMember": provider in "myVar" is null, but provider of "myMember" is ast value with "myVar".
    // In case of "(object1 + object2).member": provider of "member" is ast value of two arguments operator of "object1 + object2".
    AstValue *provider_;
    std::string name_;
public:
    AstVariableReference (std::string name, AstValue *provider = 0);
    virtual ~AstVariableReference ();

    std::string GetName ();
    AstValue *GetProvider ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
