#pragma once
#include <string>
#include <vector>

#include <ApplePie/AST/Declaration.hpp>
#include <ApplePie/AST/VariableDeclaration.hpp>
#include <ApplePie/AST/FunctionDeclaration.hpp>
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
unsigned CLASS_DECLARITION_TYPE_HASH = StringToHash ("ClassDeclarition");

class ClassDeclaration : public Declaration
{
APPLE_PIE_OBJECT_WITH_KNOWN_TYPE (ClassDeclarition, CLASS_DECLARITION_TYPE_HASH)
protected:
    std::string name_;
    std::vector <std::string> bases_;
    std::vector <VariableDeclaration *> members_;
    std::vector <FunctionDeclaration *> functions_;
public:
    ClassDeclaration (std::string name, std::vector <std::string> bases,
                      std::vector <VariableDeclaration *> &members, std::vector <FunctionDeclaration *> functions);
    virtual ~ClassDeclaration ();

    std::string GetBaseNameByIndex (int index);
    int GetBasesCount ();
    VariableDeclaration *GetMemberDeclarationByIndex (int index);
    int GetMembersCount ();
    FunctionDeclaration *GetFunctionDeclarationByIndex (int index);
    int GetFunctionsCount ();

    // Declaration interface
    std::string GetName ();
    std::string GetType ();

    // StringifyAble interface
    std::string ToString (int addSpacesIndentation = 0);
};
}
