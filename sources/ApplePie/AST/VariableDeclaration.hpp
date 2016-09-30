#pragma once
#include <string>
#include <ApplePie/AST/Declaration.hpp>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned VARIABLE_DECLARITION_TYPE_HASH = StringToHash ("VariableDeclarition");

class VariableDeclaration : public Declaration
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (VariableDeclarition, VARIABLE_DECLARITION_TYPE_HASH)
protected:
    std::string name_;
    std::string type_;
public:
    VariableDeclaration (std::string name, std::string type);
    virtual ~VariableDeclaration ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
