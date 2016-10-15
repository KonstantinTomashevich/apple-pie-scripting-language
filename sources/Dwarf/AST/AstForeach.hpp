#pragma once
#include <string>
#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/AST/AstNode.hpp>
#include <Dwarf/AST/AstVariableReference.hpp>

namespace Dwarf
{
unsigned AST_FOREACH_TYPE_HASH = StringToHash ("AstForeach");

class AstForeach : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstForeach, AST_FOREACH_TYPE_HASH)
protected:
    AstVariableReference *currentArrayElementOutput_;
    AstVariableReference *array_;
    AstNode *block_;
public:
    AstForeach (AstVariableReference *currentArrayElementOutput, AstVariableReference *array, AstNode *block);
    virtual ~AstForeach ();

    AstVariableReference *GetCurrentArrayElementOutput ();
    AstVariableReference *GetArray ();
    AstNode *GetBlock ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
