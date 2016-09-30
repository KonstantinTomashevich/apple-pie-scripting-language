#include "AstOneArgumentOperator.hpp"

namespace ApplePie
{
AstOneArgumentOperator::AstOneArgumentOperator (std::string operatorName, std::string operatorReturnType, AstValue *argument) :
    operatorName_ (operatorName),
    operatorReturnType_ (operatorReturnType),
    argument_ (argument)
{

}

AstOneArgumentOperator::~AstOneArgumentOperator ()
{
    delete argument_;
}

std::string AstOneArgumentOperator::GetOperatorName ()
{
    return operatorName_;
}

AstValue *AstOneArgumentOperator::GetArgument ()
{
    return argument_;
}

std::string AstOneArgumentOperator::GetOperatorReturnType ()
{
    return operatorReturnType_;
}

std::string AstOneArgumentOperator::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[one argument operator ";
    result += operatorName_;
    result += " which returns ";
    result += operatorReturnType_;
    result += ";\n" + indent + "argument:";
    result += argument_->ToString (addSpacesIndentation + 4);
    result += "]";
    return result;
}
}
