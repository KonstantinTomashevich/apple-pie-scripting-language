#include "AstForeach.hpp"

namespace ApplePie
{
AstForeach::AstForeach (AstVariableReference *currentArrayElementOutput, AstVariableReference *array, AstNode *block) :
    currentArrayElementOutput_ (currentArrayElementOutput),
    array_ (array),
    block_ (block)
{

}

AstForeach::~AstForeach ()
{
    delete currentArrayElementOutput_;
    delete array_;
    delete block_;
}

AstVariableReference *AstForeach::GetCurrentArrayElementOutput ()
{
    return currentArrayElementOutput_;
}

AstVariableReference *AstForeach::GetArray ()
{
    return array_;
}

AstNode *AstForeach::GetBlock ()
{
    return block_;
}

std::string AstForeach::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[foreach cycle; current array element output:\n";
    result += currentArrayElementOutput_->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "array:\n";
    result += array_->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "block:\n";
    result += block_->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "end of foreach cycle]";
    return result;
}
}
