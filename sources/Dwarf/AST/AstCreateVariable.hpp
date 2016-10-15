#pragma once
#include <string>
#include <vector>

#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/AST/VariableDeclaration.hpp>

namespace Dwarf
{
unsigned AST_CREATE_VARIABLE_TYPE_HASH = StringToHash ("AstCreateVariable");

class AstCreateVariable : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstCreateVariable, AST_CREATE_VARIABLE_TYPE_HASH)
protected:
    VariableCreationType creationType_;
    VariableDeclaration *declaration_;
    // In case of copy or ref construction, this array will contain object for copying or refering.
    // In case of new construction, this array will contain arguments for object constructor.
    std::vector <AstValue *> constructionArguments_;
    VariableConstructionType constructionType_;
public:
    AstCreateVariable (VariableCreationType creationType, VariableDeclaration *declaration,
                       std::vector <AstValue *> &constructionArguments,
                       VariableConstructionType constructionType = VARIABLE_CONSTRUCTION_NEW);
    virtual ~AstCreateVariable ();

    VariableCreationType GetCreationType ();
    VariableDeclaration *GetDeclaration ();
    AstValue *GetConstructionArgumentByIndex (int index);
    int GetConstructionArgumentsCount ();
    VariableConstructionType GetConstructionType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
