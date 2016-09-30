#pragma once
#include <string>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned AST_ONE_ARGUMENT_OPERATOR_TYPE_HASH = StringToHash ("AstOneArgumentOperator");

class AstOneArgumentOperator : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstOneArgumentOperator, AST_ONE_ARGUMENT_OPERATOR_TYPE_HASH)
protected:
    std::string operatorName_;
    std::string operatorReturnType_;
    AstValue *argument_;
public:
    AstOneArgumentOperator (std::string operatorName, std::string operatorReturnType, AstValue *argument);
    virtual ~AstOneArgumentOperator ();

    std::string GetOperatorName ();
    AstValue *GetArgument ();
    std::string GetOperatorReturnType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
