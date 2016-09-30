#pragma once
#include <string>
#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/VariableDeclaration.hpp>

namespace ApplePie
{
unsigned AST_VARIABLE_REFERENCE_TYPE_HASH = StringToHash ("AstVariableReference");

class AstVariableReference : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstVariableReference, AST_VARIABLE_REFERENCE_TYPE_HASH)
protected:
    std::string name_;
public:
    AstVariableReference (std::string name);
    virtual ~AstVariableReference ();
    std::string GetName ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
