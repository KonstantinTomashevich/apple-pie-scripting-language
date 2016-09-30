#pragma once
#include <string>
#include <vector>

#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>

namespace ApplePie
{
unsigned AST_CREATE_VARIABLE_TYPE_HASH = StringToHash ("AstCreateVariable");

class AstCreateVariable : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstCreateVariable, AST_CREATE_VARIABLE_TYPE_HASH)
protected:
    VariableCreationType creationType_;
    // TODO: Use variable declaration!
    std::string name_;
    std::string typeName_;
    std::vector <AstValue *> constructionArguments_;
public:
    AstCreateVariable (VariableCreationType creationType, std::string name, std::string typeName,
                       std::vector <AstValue *> &constructionArguments);
    virtual ~AstCreateVariable ();

    VariableCreationType GetCreationType ();
    std::string GetName ();
    std::string GetTypeName ();
    AstValue *GetConstructionArgumentByIndex (int index);
    int GetConstructionArgumentsCount ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
