#pragma once
#include <string>
#include <vector>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned VARIABLE_DECLARITION_TYPE_HASH = StringToHash ("VariableDeclarition");
unsigned FUNCTION_DECLARATION_TYPE_HASH = StringToHash ("FunctionDeclaration");
unsigned CLASS_DECLARITION_TYPE_HASH = StringToHash ("ClassDeclarition");

class Declaration : public StringifyAble, public ObjectWithKnownType
{
public:
    virtual std::string GetName () = 0;
    virtual std::string GetType () = 0;
};

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

class FunctionDeclaration : public Declaration
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (FunctionDeclaration, FUNCTION_DECLARATION_TYPE_HASH)
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

class ClassDeclaration : public Declaration
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (ClassDeclarition, CLASS_DECLARITION_TYPE_HASH)
protected:
    std::string name_;
    std::vector <ClassDeclaration *> bases_;
    std::vector <VariableDeclaration *> members_;
    std::vector <FunctionDeclaration *> functions_;
public:
    ClassDeclaration (std::string name, std::vector <ClassDeclaration *> bases,
                      std::vector <VariableDeclaration *> &members, std::vector <FunctionDeclaration *> functions);
    virtual ~ClassDeclaration ();

    ClassDeclaration *GetBaseDeclarationByIndex (int index);
    int GetBasesCount ();
    VariableDeclaration *GetMemberDeclarationByIndex (int index);
    int GetMembersCount ();
    FunctionDeclaration *GetFunctionDeclarationByIndex (int index);
    int GetFunctionsCount ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
