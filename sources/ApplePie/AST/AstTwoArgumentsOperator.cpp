#include "AstTwoArgumentsOperator.hpp"

namespace ApplePie
{
AstTwoArgumentsOperators::AstTwoArgumentsOperators (std::string operatorName, std::string operatorReturnType, AstValue *firstArgument, AstValue *secondArgument) :
    operatorName_ (operatorName),
    operatorReturnType_ (operatorReturnType),
    firstArgument_ (firstArgument),
    secondArgument_ (secondArgument)
{

}

AstTwoArgumentsOperators::~AstTwoArgumentsOperators ()
{
    delete firstArgument_;
    delete secondArgument_;
}

std::string AstTwoArgumentsOperators::GetOperatorName ()
{
    return operatorName_;
}

AstValue *AstTwoArgumentsOperators::GetFirstArgument ()
{
    return firstArgument_;
}

AstValue *AstTwoArgumentsOperators::GetSecondArgument ()
{
    return secondArgument_;
}

std::string AstTwoArgumentsOperators::GetOperatorReturnType ()
{
    return operatorReturnType_;
}

std::string AstTwoArgumentsOperators::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[two arguments operator ";
    result += operatorName_;
    result += " which returns ";
    result += operatorReturnType_;
    result += ";\n" + indent + "first argument:\n";
    result += firstArgument_->ToString (addSpacesIndentation + 4);
    result += indent + "second argument:\n";
    result += secondArgument_->ToString (addSpacesIndentation + 4);
    result += "end of two arguments operator]";
    return result;
}
}
