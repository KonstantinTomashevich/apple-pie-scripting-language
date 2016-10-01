#include "AstVariableReference.hpp"

namespace ApplePie
{
AstVariableReference::AstVariableReference (std::string name, AstValue *provider) :
    name_ (name),
    provider_ (provider)
{

}

AstVariableReference::~AstVariableReference ()
{
    delete provider_;
}

std::string AstVariableReference::GetName ()
{
    return name_;
}

AstValue *AstVariableReference::GetProvider ()
{
    return provider_;
}

std::string AstVariableReference::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[variable reference ";
    result += name_;
    if (provider_)
    {
        result += "\n" + indent + "provider:\n";
        result += provider_->ToString (addSpacesIndentation + 4) + "\n";
        result += indent + "end of variable reference]";
    }
    else
        result += "]";
    return result;
}
}

