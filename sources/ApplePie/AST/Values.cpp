#include "Values.hpp"
#include <assert.h>
namespace ApplePie
{

AstNode::AstNode () :
    childValues_ ()
{

}

AstNode::~AstNode ()
{
    for (int index = 0; index < childValues_.size (); index++)
        delete childValues_.at (index);
    childValues_.clear ();
}

void AstNode::PushValue (AstValue *value)
{
    childValues_.push_back (value);
}

AstValue *AstNode::GetAtIndex (int index)
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

AstVariable::AstVariable (std::string name) :
    name_ (name)
{

}

AstVariable::~AstVariable ()
{

}

std::string AstVariable::GetName ()
{
    return name_;
}

std::string AstVariable::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[variable ";
    result += name_;
    result += "]";
    return result;
}

AstCreateVariable::AstCreateVariable (VariableCreationType creationType, std::string name,
                                      std::string typeName, std::vector <AstValue *> &constructionArguments) :
    creationType_ (creationType),
    name_ (name),
    typeName_ (typeName),
    constructionArguments_ (constructionArguments)
{

}

AstCreateVariable::~AstCreateVariable ()
{
    for (int index = 0; index < constructionArguments_.size (); index++)
        delete constructionArguments_.at (index);
    constructionArguments_.clear ();
}

VariableCreationType AstCreateVariable::GetCreationType ()
{
    return creationType_;
}

AstValue *AstCreateVariable::GetConstructionArgumentByIndex (int index)
{
    assert (index < constructionArguments_.size ());
    return constructionArguments_.at (index);
}

int AstCreateVariable::GetConstructionArgumentsCount ()
{
    return constructionArguments_.size ();
}

std::string AstCreateVariable::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[create ";
    if (creationType_ == VARIABLE_LOCAL)
        result += "local ";
    else if (creationType_ == VARIABLE_GLOBAL)
        result += "global ";
    else if (creationType_ == VARIABLE_CLASS_MEMBER)
        result += "class member ";
    else
        result += "ERROR_UNKNOWN_CREATION_TYPE ";

    result += "variable ";
    result += name_;
    result += " of type ";
    result += typeName_;
    result += ";\n" + indent + "construction arguments:";

    if (constructionArguments_.size () > 0)
        for (int index = 0; index < constructionArguments_.size (); index++)
            result += constructionArguments_.at (index)->ToString (addSpacesIndentation + 4) + "\n";

    result += indent + "end of ";
    if (creationType_ == VARIABLE_LOCAL)
        result += "local ";
    else if (creationType_ == VARIABLE_GLOBAL)
        result += "global ";
    else if (creationType_ == VARIABLE_CLASS_MEMBER)
        result += "class member ";
    else
        result += "ERROR_UNKNOWN_CREATION_TYPE ";
    result += "variable construction]";
    return result;
}
}

