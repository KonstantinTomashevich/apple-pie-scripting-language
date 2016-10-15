#pragma once
#include <string>
#include <vector>

#include <Dwarf/AST/AstValue.hpp>
#include <Dwarf/AST/AstFunction.hpp>
#include <Dwarf/AST/AstCall.hpp>
#include <Dwarf/AST/ClassDeclaration.hpp>
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
unsigned AST_CLASS_TYPE_HASH = StringToHash ("AstClass");

class AstClass : AstValue
{
DWARF_OBJECT_WITH_KNOWN_TYPE (AstClass, AST_CLASS_TYPE_HASH)
protected:
    std::string name_;
    std::vector <AstCall *> basesConstructorsCalls_;
    AstFunction *constructor_;
    std::vector <AstFunction *> functions_;
    ClassDeclaration *generatedDeclaration_;

    void GenerateDeclaration ();
public:
    AstClass (std::string name, std::vector <AstCall *> basesConstructorsCalls,
              AstFunction *constructor, std::vector <AstFunction *> functions);
    virtual ~AstClass ();

    std::string GetName ();
    AstCall *GetBaseConstructorCallByIndex (int index);
    int GetBasesConstructorsCallsCount ();

    AstFunction *GetConstructor ();
    AstFunction *GetFunctionByIndex (int index);
    int GetFunctionsCount ();
    ClassDeclaration *GetGeneratedDeclaration ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
