#pragma once
#include <string>
#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/AstNode.hpp>
#include <ApplePie/AST/AstVariableReference.hpp>

namespace ApplePie
{
// TODO: Make AstForeach later.
unsigned AST_FOR_TYPE_HASH = StringToHash ("AstFor");

class AstFor : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstFor, AST_FOR_TYPE_HASH)
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
