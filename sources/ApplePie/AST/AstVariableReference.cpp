#include "AstVariableReference.hpp"

namespace ApplePie
{
AstVariableReference::AstVariableReference (std::string name) :
    name_ (name)
{

}

AstVariableReference::~AstVariableReference ()
{

}

std::string AstVariableReference::GetName ()
{
    return name_;
}

std::string AstVariableReference::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[variable ";
    result += name_;
    result += "]";
    return result;
}
}

