#pragma once
#include <string>
#include <vector>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned AST_NODE_TYPE_HASH = StringToHash ("AstNode");
unsigned AST_VARIABLE_TYPE_HASH = StringToHash ("AstVariable");
unsigned AST_CREATE_VARIABLE_TYPE_HASH = StringToHash ("AstCreateVariable");

class AstValue : public StringifyAble, public ObjectWithKnownType
{
public:
    // TODO: Notning now. Bytecode generation will be later.
};

class AstNode : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstNode, AST_NODE_TYPE_HASH)
protected:
    std::vector <AstValue *> childValues_;
public:
    AstNode ();
    virtual ~AstNode ();

    void PushValue (AstValue *value);
    AstValue *GetAtIndex (int index);
    int GetValuesCount ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};

class AstVariable : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstVariable, AST_VARIABLE_TYPE_HASH)
protected:
    std::string name_;
public:
    AstVariable (std::string name);
    virtual ~AstVariable ();
    std::string GetName ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};

class AstCreateVariable : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstCreateVariable, AST_CREATE_VARIABLE_TYPE_HASH)
protected:
    VariableCreationType creationType_;
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

