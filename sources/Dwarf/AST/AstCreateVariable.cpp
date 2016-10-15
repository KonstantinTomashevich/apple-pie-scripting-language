#include "AstCreateVariable.hpp"
#include <assert.h>

namespace Dwarf
{
AstCreateVariable::AstCreateVariable (VariableCreationType creationType, VariableDeclaration *declaration,
                                      std::vector <AstValue *> &constructionArguments,
                                      VariableConstructionType constructionType) :
    creationType_ (creationType),
    declaration_ (declaration),
    constructionArguments_ (constructionArguments),
    constructionType_ (constructionType)
{
    assert (declaration_);
}

AstCreateVariable::~AstCreateVariable ()
{
    if (!constructionArguments_.empty ())
        for (int index = 0; index < constructionArguments_.size (); index++)
            delete constructionArguments_.at (index);
    constructionArguments_.clear ();
}

VariableCreationType AstCreateVariable::GetCreationType ()
{
    return creationType_;
}

VariableDeclaration *AstCreateVariable::GetDeclaration ()
{
    return declaration_;
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

VariableConstructionType AstCreateVariable::GetConstructionType ()
{
    return constructionType_;
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
    result += declaration_->GetName ();
    result += " of type ";
    result += declaration_->GetType ();

    result += ";\n" + indent + "construction type: ";
    if (constructionType_ == VARIABLE_CONSTRUCTION_NEW)
        result += "new;\n";
    else if (constructionType_ == VARIABLE_CONSTRUCTION_COPY)
            result += "copy;\n";
    else if (constructionType_ == VARIABLE_CONSTRUCTION_REF)
            result += "ref;\n";
    else
            result += "UNKNOWN;\n";

    result += indent + "construction arguments:\n";
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

