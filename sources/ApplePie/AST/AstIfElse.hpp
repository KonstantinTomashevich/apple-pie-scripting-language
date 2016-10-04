#pragma once
#include <string>
#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/AstNode.hpp>

namespace ApplePie
{
unsigned AST_IF_ELSE_TYPE_HASH = StringToHash ("AstIfElse");

class AstIfElse : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstIfElse, AST_IF_ELSE_TYPE_HASH)
protected:
    // AstOneArgumentOperator which returns Bool,
    // or AstTwoArgumentsOperator which returns Bool,
    // or AstVariableReference to variable with Bool type.
    AstValue *condition_;
    AstNode *ifConditionTrueBlock_;
    // Can be null.
    AstNode *ifConditionFalseBlock_;
public:
    AstIfElse (AstValue *condition, AstNode *ifConditionTrueBlock, AstNode *ifConditionFalseBlock = 0);
    virtual ~AstIfElse ();

    AstValue *GetCondition ();
    AstNode *GetIfConditionTrueBlock ();
    AstNode *GetIfConditionFalseBlock ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
