#pragma once
#include <string>
#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/AstNode.hpp>

namespace ApplePie
{
unsigned AST_WHILE_TYPE_HASH = StringToHash ("AstWhile");

class AstWhile : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstWhile, AST_WHILE_TYPE_HASH)
protected:
    // AstOneArgumentOperator which returns Bool,
    // or AstTwoArgumentsOperator which returns Bool,
    // or AstVariableReference to variable with Bool type.
    AstValue *condition_;
    AstNode *block_;
    // If false, same as "while (...) {...}" in C++. If true, same as "do {...} while (...);" in C++.
    bool checkConditionAfterExecutingBlock_;
public:
    AstWhile (AstValue *condition, AstNode *block, bool checkConditionAfterExecutingBlock = false);
    virtual ~AstWhile ();

    AstValue *GetCondition ();
    AstNode *GetBlock ();
    bool IsCheckConditionAfterExecutingBlock ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
