#include "FunctionDeclaration.hpp"
#include <assert.h>

namespace ApplePie
{
FunctionDeclaration::FunctionDeclaration (std::string name, std::string returnType,
                                          std::vector <VariableDeclaration *> &arguments) :
    name_ (name),
    returnType_ (returnType),
    arguments_ (arguments)
{

}

FunctionDeclaration::~FunctionDeclaration()
{
    for (int index = 0; index < arguments_.size (); index++)
        delete arguments_.at (index);
    arguments_.clear ();
}

std::string FunctionDeclaration::GetReturnType ()
{
    return returnType_;
}

VariableDeclaration *FunctionDeclaration::GetArgumentDeclarationByIndex (int index)
{
    assert (index < arguments_.size ());
    return arguments_.at (index);
}

int FunctionDeclaration::GetArgumentsCount ()
{
    return arguments_.size ();
}

std::string FunctionDeclaration::GetName ()
{
    return name_;
}

std::string FunctionDeclaration::GetType ()
{
    return "Function";
}

std::string FunctionDeclaration::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[function declaration ";
    result += name_;
    result += ";returns ";
    result += returnType_;
    result += ";requires arguments:\n";

    for (int index = 0; index < arguments_.size (); index++)
        result += arguments_.at (index)->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "end of function declaration]";
    return result;
}
}
