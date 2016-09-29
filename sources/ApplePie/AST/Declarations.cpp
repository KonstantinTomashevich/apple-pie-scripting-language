#include "Declarations.hpp"

namespace ApplePie
{

VariableDeclaration::VariableDeclaration (std::string name, std::string type) :
    name_ (name),
    type_ (type)
{

}

VariableDeclaration::~VariableDeclaration ()
{

}

std::string VariableDeclaration::GetName ()
{
    return name_;
}

std::string VariableDeclaration::GetType ()
{
    return type_;
}

std::string VariableDeclaration::ToString ()
{
    std::string result = "";
    result += "[variable ";
    result += name_;
    result += " of type ";
    result += type_;
    result += "]";
    return result;
}

FunctionDeclarition::FunctionDeclarition (std::string name, std::string returnType,
                                          std::vector <VariableDeclaration *> &arguments) :
    name_ (name),
    returnType_ (returnType),
    arguments_ (arguments)
{

}

FunctionDeclarition::~FunctionDeclarition()
{
    for (int index = 0; index < arguments_.size (); index++)
        delete arguments_.at (index);
    arguments_.clear ();
}

std::string FunctionDeclarition::GetReturnType ()
{
    return returnType_;
}

std::string FunctionDeclarition::GetName ()
{
    return name_;
}

std::string FunctionDeclarition::GetType ()
{
    return "Function";
}

std::string FunctionDeclarition::ToString ()
{
    std::string result;
    result += "[function ";
    result += name_;
    result += ";returns ";
    result += returnType_;
    result += ";requires arguments: ";

    for (int index = 0; index < arguments_.size (); index++)
        result += arguments_.at (index)->ToString ();
    result += " ]";
    return result;
}

std::vector <VariableDeclaration *> *FunctionDeclarition::GetArgumentsDeclaritionsVector ()
{
    return &arguments_;
}
}

