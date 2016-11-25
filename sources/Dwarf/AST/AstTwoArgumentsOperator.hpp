#pragma once
#include <string>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
const unsigned AST_TWO_ARGUMENT_OPERATOR_TYPE_HASH = StringToHash ("AstTwoArgumentsOperator");

class AstTwoArgumentsOperators : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstTwoArgumentsOperator, AST_TWO_ARGUMENT_OPERATOR_TYPE_HASH)
protected:
    std::string operatorName_;
    std::string operatorReturnType_;
    AstValue *firstArgument_;
    AstValue *secondArgument_;
public:
    AstTwoArgumentsOperators (std::string operatorName, std::string operatorReturnType,
                              AstValue *firstArgument, AstValue *secondArgument);
    virtual ~AstTwoArgumentsOperators ();

    std::string GetOperatorName ();
    AstValue *GetFirstArgument ();
    AstValue *GetSecondArgument ();
    std::string GetOperatorReturnType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
