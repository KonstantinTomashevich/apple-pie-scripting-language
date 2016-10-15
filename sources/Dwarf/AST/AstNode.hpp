#pragma once
#include <string>
#include <vector>

#include <Dwarf/Utils.hpp>
#include <Dwarf/AST/AstValue.hpp>

namespace Dwarf
{
unsigned AST_NODE_TYPE_HASH = StringToHash ("AstNode");

class AstNode : public AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstNode, AST_NODE_TYPE_HASH)
protected:
    std::vector <AstValue *> childValues_;
public:
    AstNode ();
    virtual ~AstNode ();

    void PushValue (AstValue *value);
    AstValue *GetValueByIndex (int index);
    int GetValuesCount ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
