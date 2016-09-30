#include "AstNumericLiteral.hpp"

namespace ApplePie
{
AstNumericLiteral::AstNumericLiteral (double value) :
    value_ (value)
{

}

AstNumericLiteral::~AstNumericLiteral ()
{

}

double AstNumericLiteral::GetValue ()
{
    return value_;
}

std::string AstNumericLiteral::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[numeric literal ";
    result += DoubleToString (value_);
    result += "]";
    return result;
}
}

