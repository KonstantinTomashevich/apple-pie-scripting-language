#include "AstVariable.hpp"

namespace ApplePie
{
AstVariable::AstVariable (std::string name) :
    name_ (name)
{

}

AstVariable::~AstVariable ()
{

}

std::string AstVariable::GetName ()
{
    return name_;
}

std::string AstVariable::ToString (int addSpacesIndentation)
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

