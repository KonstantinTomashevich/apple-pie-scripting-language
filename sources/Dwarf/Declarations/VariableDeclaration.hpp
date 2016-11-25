#pragma once
#include <string>
#include <Dwarf/Declarations/Declaration.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
unsigned VARIABLE_DECLARITION_TYPE_HASH = StringToHash ("VariableDeclarition");

class VariableDeclaration : public Declaration
{
DWARF_OBJECT_WITH_KNOWN_TYPE (VariableDeclarition, VARIABLE_DECLARITION_TYPE_HASH)
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
