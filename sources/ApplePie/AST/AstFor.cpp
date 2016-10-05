#include "AstFor.hpp"

namespace ApplePie
{
AstFor::AstFor (AstVariableReference *counter, Range range, AstNode *block) :
    counter_ (counter),
    range_ (range),
    block_ (block)
{

}

AstFor::~AstFor ()
{
    delete counter_;
    delete block_;
}

AstVariableReference *AstFor::GetCounter ()
{
    return counter_;
}

Range AstFor::GetRange ()
{
    return range_;
}

AstNode *AstFor::GetBlock ()
{
    return block_;
}

std::string AstFor::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[for cycle; counter variable:\n";
    result += counter_->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "in range from " + DoubleToString (range_.minimum_) +
            " to " + DoubleToString (range_.maximum_) + " with step " +
            DoubleToString (range_.step_) + "\n";

    result += indent + "block:\n";
    result += block_->ToString (addSpacesIndentation + 4) + "\n";
    result += "end of for cycle]";
    return result;
}
}
