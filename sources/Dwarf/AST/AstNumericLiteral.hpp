#pragma once
#include <string>
#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>

namespace Dwarf
{
unsigned AST_NUMERIC_LITERAL_TYPE_HASH = StringToHash ("AstNumericLiteral");

class AstNumericLiteral : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstNumericLiteral, AST_NUMERIC_LITERAL_TYPE_HASH)
protected:
    double value_;
public:
    AstNumericLiteral (double value);
    virtual ~AstNumericLiteral ();
    double GetValue ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
