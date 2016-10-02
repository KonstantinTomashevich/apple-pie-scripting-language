#include "AstFunction.hpp"

namespace ApplePie
{

AstFunction::AstFunction (FunctionDeclaration *declaration, AstNode *body) :
    declaration_ (declaration),
    body_ (body)
{

}

AstFunction::~AstFunction ()
{
    delete declaration_;
    delete body_;
}

AstNode *AstFunction::GetBody ()
{
    return body_;
}

std::string AstFunction::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[function\n";
    result += declaration_->ToString (addSpacesIndentation + 4);
    result += indent + "body:\n";
    result += body_->ToString (addSpacesIndentation + 4);
    result += indent + "end of function]";
    return result;
}
}

