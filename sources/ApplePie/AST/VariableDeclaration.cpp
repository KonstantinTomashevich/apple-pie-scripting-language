#include "VariableDeclaration.hpp"

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

std::string VariableDeclaration::ToString (int addSpacesIndentation)
{
    std::string result = "";
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[variable ";
    result += name_;
    result += " of type ";
    result += type_;
    result += "]";
    return result;
}
}
