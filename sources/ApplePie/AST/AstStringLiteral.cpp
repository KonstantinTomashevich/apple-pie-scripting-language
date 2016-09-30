#include "AstStringLiteral.hpp"

namespace ApplePie
{
AstStringLiteral::AstStringLiteral (std::string value) :
    value_ (value)
{

}

AstStringLiteral::~AstStringLiteral ()
{

}

std::string AstStringLiteral::GetValue ()
{
    return value_;
}

std::string AstStringLiteral::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[String literal \"";
    result += value_;
    result += "\"]";
    return result;
}
}
