#pragma once
#include <string>
#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>

namespace Dwarf
{
const unsigned AST_STRING_LITERAL_TYPE_HASH = StringToHash ("AstStringLiteral");

class AstStringLiteral : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (StringLiteral, AST_STRING_LITERAL_TYPE_HASH)
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
