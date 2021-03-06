#pragma once
#include <string>
#include <vector>

#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
const unsigned AST_CALL_TYPE_HASH = StringToHash ("AstCall");

class AstCall : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstCall, AST_CALL_TYPE_HASH)
protected:
    // Same as provider in AstVariableReference.
    AstValue *provider_;
    std::string calledFunction_;
    std::vector <AstValue *> arguments_;
public:
    AstCall (std::string calledFunction, std::vector <AstValue *> arguments, AstValue *provider = 0);
    virtual ~AstCall ();

    std::string GetCalledFunctionName ();
    AstValue *GetArgumentByIndex (int index);
    int GetArgumentsCount ();
    AstValue *GetProvider ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
