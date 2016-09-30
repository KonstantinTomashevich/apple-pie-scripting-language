#pragma once
#include <string>
#include <vector>

#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/VariableDeclaration.hpp>

namespace ApplePie
{
unsigned AST_CREATE_VARIABLE_TYPE_HASH = StringToHash ("AstCreateVariable");

class AstCreateVariable : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstCreateVariable, AST_CREATE_VARIABLE_TYPE_HASH)
protected:
    VariableCreationType creationType_;
    VariableDeclaration *declaration_;
    std::vector <AstValue *> constructionArguments_;
public:
    AstCreateVariable (VariableCreationType creationType, VariableDeclaration *declaration,
                       std::vector <AstValue *> &constructionArguments);
    virtual ~AstCreateVariable ();

    VariableCreationType GetCreationType ();
    VariableDeclaration *GetDeclaration ();
    AstValue *GetConstructionArgumentByIndex (int index);
    int GetConstructionArgumentsCount ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
