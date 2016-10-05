#include "AstWhile.hpp"
#include <assert.h>

namespace ApplePie
{
AstWhile::AstWhile (AstValue *condition, AstNode *block, bool checkConditionAfterExecutingBlock) :
    condition_ (condition),
    block_ (block),
    checkConditionAfterExecutingBlock_ (checkConditionAfterExecutingBlock)
{
    assert (condition_);
    assert (block_);
}

AstWhile::~AstWhile ()
{
    delete condition_;
    delete block_;
}

AstValue *AstWhile::GetCondition ()
{
    return condition_;
}

AstNode *AstWhile::GetBlock ()
{
    return block_;
}

bool AstWhile::IsCheckConditionAfterExecutingBlock ()
{
    return checkConditionAfterExecutingBlock_;
}

std::string AstWhile::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[";
    if (checkConditionAfterExecutingBlock_)
        result += "do_while ";
    else
        result += "while ";

    result += "with condition:\n";
    result += condition_->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "with block:\n";
    result += block_->ToString (addSpacesIndentation + 4) + "\n";

    if (checkConditionAfterExecutingBlock_)
        result += "end of do_while]";
    else
        result += "end of while]";
    return result;
}
}

