#pragma once
#include <string>
#include <vector>

#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>

namespace ApplePie
{
unsigned AST_VARIABLE_TYPE_HASH = StringToHash ("AstVariable");

class AstVariable : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstVariable, AST_VARIABLE_TYPE_HASH)
protected:
    // TODO: Use variable declaration!
    std::string name_;
public:
    AstVariable (std::string name);
    virtual ~AstVariable ();
    std::string GetName ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
