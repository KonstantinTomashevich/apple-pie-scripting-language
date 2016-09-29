#pragma once
#include <string>
#include <vector>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned VARIABLE_DECLARITION_TYPE_HASH = StringToHash ("VariableDeclarition");
unsigned FUNCTION_DECLARITION_TYPE_HASH = StringToHash ("FunctionDeclarition");

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
    std::string ToString ();
};

class FunctionDeclarition : public Declaration
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (FunctionDeclarition, FUNCTION_DECLARITION_TYPE_HASH)
protected:
    std::string name_;
    std::string returnType_;
    std::vector <VariableDeclaration *> arguments_;
public:
    FunctionDeclarition (std::string name, std::string returnType, std::vector <VariableDeclaration *> &arguments);
    virtual ~FunctionDeclarition ();

    std::string GetReturnType ();
    std::vector <VariableDeclaration *> *GetArgumentsDeclaritionsVector();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString ();
};
}
