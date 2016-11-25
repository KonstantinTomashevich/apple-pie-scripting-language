#pragma once
#include <string>
#include <vector>

#include <Dwarf/Declarations/Declaration.hpp>
#include <Dwarf/Declarations/VariableDeclaration.hpp>
#include <Dwarf/Declarations/FunctionDeclaration.hpp>
#include <Dwarf/Declarations/ClassDeclaration.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
const unsigned PACKAGE_DECLARATION_TYPE_HASH = StringToHash ("PackageDeclaration");

class PackageDeclaration : public Declaration
{
DWARF_OBJECT_WITH_KNOWN_TYPE (PackageDeclaration, PACKAGE_DECLARATION_TYPE_HASH)
protected:
    std::string name_;
    std::vector <Declaration *> declarationsInside_;
public:
    PackageDeclaration (std::string name, std::vector <Declaration *> declarationsInside);
    virtual ~PackageDeclaration ();

    Declaration *GetDeclarationByIndex(int index);
    int GetDeclarationsCount ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
