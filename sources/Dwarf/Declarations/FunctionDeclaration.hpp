#pragma once
#include <string>
#include <vector>

#include <Dwarf/Declarations/Declaration.hpp>
#include <Dwarf/Declarations/VariableDeclaration.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
const unsigned FUNCTION_DECLARATION_TYPE_HASH = StringToHash ("FunctionDeclaration");

class FunctionDeclaration : public Declaration
{
DWARF_OBJECT_WITH_KNOWN_TYPE (FunctionDeclaration, FUNCTION_DECLARATION_TYPE_HASH)
protected:
    std::string name_;
    std::string returnType_;
    std::vector <VariableDeclaration *> arguments_;
public:
    FunctionDeclaration (std::string name, std::string returnType, std::vector <VariableDeclaration *> &arguments);
    virtual ~FunctionDeclaration ();

    std::string GetReturnType ();
    VariableDeclaration *GetArgumentDeclarationByIndex (int index);
    int GetArgumentsCount ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
