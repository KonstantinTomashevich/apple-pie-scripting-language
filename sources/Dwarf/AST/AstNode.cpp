#include "AstNode.hpp"
#include <assert.h>

namespace Dwarf
{
AstNode::AstNode () :
    childValues_ ()
{

}

AstNode::~AstNode ()
{
    if (!childValues_.empty ())
        for (int index = 0; index < childValues_.size (); index++)
            delete childValues_.at (index);
    childValues_.clear ();
}

void AstNode::PushValue (AstValue *value)
{
    childValues_.push_back (value);
}

AstValue *AstNode::GetValueByIndex (int index)
{
    assert (index < childValues_.size ());
    return childValues_.at (index);
}

int AstNode::GetValuesCount ()
{
    return childValues_.size ();
}

std::string AstNode::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[node:\n";
    for (int index = 0; index < childValues_.size (); index++)
        result += childValues_.at (index)->ToString (addSpacesIndentation + 4) + "\n";
    result += indent + "end of node child values]";
    return result;
}
}
