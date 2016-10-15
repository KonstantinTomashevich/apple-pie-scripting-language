#include "AstCall.hpp"
#include <assert.h>

namespace Dwarf
{
AstCall::AstCall (std::string calledFunction, std::vector <AstValue *> arguments, AstValue *provider) :
    calledFunction_ (calledFunction),
    arguments_ (arguments),
    provider_ (provider)
{
    assert (!calledFunction.empty ());
}

AstCall::~AstCall ()
{
    if (!arguments_.empty ())
        for (int index = 0; index < arguments_.size (); index++)
            delete arguments_.at (index);
    arguments_.clear ();
    delete provider_;
}

std::string AstCall::GetCalledFunctionName ()
{
    return calledFunction_;
}

AstValue *AstCall::GetArgumentByIndex (int index)
{
    assert (index < arguments_.size ());
    return arguments_.at (index);
}

int AstCall::GetArgumentsCount ()
{
    return arguments_.size ();
}

AstValue *AstCall::GetProvider ()
{
    return provider_;
}

std::string AstCall::ToString(int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[call of function ";
    result += calledFunction_;
    result += ";\n" + indent + "arguments:\n";

    for (int index = 0; index < arguments_.size (); index++)
        result += arguments_.at (index)->ToString (addSpacesIndentation + 4) + "\n";

    if (provider_)
    {
        result += indent + "provider:\n";
        result += provider_->ToString (addSpacesIndentation + 4) + "\n";
    }
    result += indent + "end of function call]";
    return result;
}
}
