#pragma once
#include <string>
#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/AST/AstNode.hpp>
#include <Dwarf/AST/AstVariableReference.hpp>

namespace Dwarf
{
const unsigned AST_FOR_TYPE_HASH = StringToHash ("AstFor");

class AstFor : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE(AstFor, AST_FOR_TYPE_HASH)
protected:
    AstVariableReference *counter_;
    Range range_;
    AstNode *block_;
public:
    AstFor (AstVariableReference *counter, Range range, AstNode *block);
    virtual ~AstFor ();

    AstVariableReference *GetCounter ();
    Range GetRange ();
    AstNode *GetBlock ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
