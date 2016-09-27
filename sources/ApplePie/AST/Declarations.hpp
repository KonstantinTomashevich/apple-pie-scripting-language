#pragma once
#include <string>
#include <vector>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
class Declaration : public StringifyAble, public ObjectWithKnownType
{
public:
    virtual std::string GetName () = 0;
    virtual std::string GetType () = 0;
};

class VariableDeclaration : public Declaration
{
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

    // ObjectWithKnownType interface
    virtual std::string GetObjectTypeName ();
};

class FunctionDeclarition : public Declaration
{
protected:
    std::string name_;
    std::string returnType_;
    std::vector <VariableDeclaration> arguments_;
public:
    FunctionDeclarition (std::string name, std::string returnType, std::vector <VariableDeclaration> &arguments);
    virtual ~FunctionDeclarition ();

    std::string GetReturnType ();
    std::vector <VariableDeclaration> *GetArgumentsDeclaritionsVector ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString ();

    // ObjectWithKnownType interface
    virtual std::string GetObjectTypeName ();
};
}
