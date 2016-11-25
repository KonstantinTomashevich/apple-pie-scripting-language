#pragma once
#include <string>
#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/AST/AstNode.hpp>
#include <Dwarf/Declarations/FunctionDeclaration.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
const unsigned AST_FUNCTION_TYPE_HASH = StringToHash ("AstFunction");

class AstFunction : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstFunction, AST_FUNCTION_TYPE_HASH)
protected:
    FunctionDeclaration *declaration_;
    AstNode *body_;
public:
    AstFunction (FunctionDeclaration *declaration, AstNode *body);
    virtual ~AstFunction ();

    FunctionDeclaration *GetDeclaration ();
    AstNode *GetBody ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
