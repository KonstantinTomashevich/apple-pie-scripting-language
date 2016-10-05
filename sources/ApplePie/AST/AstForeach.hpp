#pragma once
#include <string>
#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/AstNode.hpp>
#include <ApplePie/AST/AstVariableReference.hpp>

namespace ApplePie
{
unsigned AST_FOREACH_TYPE_HASH = StringToHash ("AstForeach");

class AstForeach : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstForeach, AST_FOREACH_TYPE_HASH)
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
