#pragma once
#include <string>
#include <ApplePie/AST/AstValue.hpp>
#include <ApplePie/AST/FunctionDeclaration.hpp>
#include <ApplePie/AST/AstNode.hpp>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned AST_FUNCTION_TYPE_HASH = StringToHash ("AstFunction");

class AstFunction : AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstFunction, AST_FUNCTION_TYPE_HASH)
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
