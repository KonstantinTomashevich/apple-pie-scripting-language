#pragma once
#include <string>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
unsigned AST_ONE_ARGUMENT_OPERATOR_TYPE_HASH = StringToHash ("AstOneArgumentOperator");

class AstOneArgumentOperator : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstOneArgumentOperator, AST_ONE_ARGUMENT_OPERATOR_TYPE_HASH)
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
