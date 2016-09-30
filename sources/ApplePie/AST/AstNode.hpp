#pragma once
#include <string>
#include <vector>

#include <ApplePie/Utils.hpp>
#include <ApplePie/AST/AstValue.hpp>

namespace ApplePie
{
unsigned AST_NODE_TYPE_HASH = StringToHash ("AstNode");

class AstNode : public AstValue
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (AstNode, AST_NODE_TYPE_HASH)
protected:
    std::vector <AstValue *> childValues_;
public:
    AstNode ();
    virtual ~AstNode ();

    void PushValue (AstValue *value);
    AstValue *GetAtIndex (int index);
    int GetValuesCount ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
