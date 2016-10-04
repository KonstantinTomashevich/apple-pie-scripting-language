#include "AstIfElse.hpp"

namespace ApplePie
{
AstIfElse::AstIfElse (AstValue *condition, AstNode *ifConditionTrueBlock, AstNode *ifConditionFalseBlock) :
    condition_ (condition),
    ifConditionTrueBlock_ (ifConditionTrueBlock),
    ifConditionFalseBlock_ (ifConditionFalseBlock)
{

}

AstIfElse::~AstIfElse ()
{
    delete condition_;
    delete ifConditionTrueBlock_;
    if (ifConditionFalseBlock_)
        delete ifConditionFalseBlock_;
}

AstValue *AstIfElse::GetCondition ()
{
    return condition_;
}

AstNode *AstIfElse::GetIfConditionTrueBlock ()
{
    return ifConditionTrueBlock_;
}

AstNode *AstIfElse::GetIfConditionFalseBlock ()
{
    return ifConditionFalseBlock_;
}

std::string AstIfElse::ToString(int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[if-else with condition:\n";
    result += condition_->ToString (addSpacesIndentation + 4);
    result += indent + "if true do block:\n";
    result += ifConditionTrueBlock_->ToString (addSpacesIndentation + 4);

    if  (ifConditionFalseBlock_)
    {
        result += indent + "else do block:\n";
        result += ifConditionFalseBlock_->ToString (addSpacesIndentation + 4);
    }
    result += indent + "end of if-else]";
    return result;
}
}
