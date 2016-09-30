#pragma once
#include <string>
#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>

namespace ApplePie
{
unsigned AST_STRING_LITERAL_TYPE_HASH = StringToHash ("AstStringLiteral");

class AstStringLiteral : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstStringLiteral, AST_STRING_LITERAL_TYPE_HASH)
protected:
    std::string value_;
public:
    AstStringLiteral (std::string value);
    virtual ~AstStringLiteral ();
    std::string GetValue ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
