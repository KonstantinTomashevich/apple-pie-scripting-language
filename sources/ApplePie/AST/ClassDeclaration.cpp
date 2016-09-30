#include "ClassDeclaration.hpp"
#include <assert.h>

namespace ApplePie
{
ClassDeclaration::ClassDeclaration (std::string name, std::vector<ClassDeclaration *> bases,
                                    std::vector <VariableDeclaration *> &members,
                                    std::vector <FunctionDeclaration *> functions) :
    name_ (name),
    bases_ (bases),
    members_ (members),
    functions_ (functions)
{

}

ClassDeclaration::~ClassDeclaration ()
{
    for (int index = 0; index < members_.size (); index++)
        delete members_.at (index);
    members_.clear ();

    for (int index = 0; index < functions_.size (); index++)
        delete functions_.at (index);
    functions_.clear ();
}

ClassDeclaration *ClassDeclaration::GetBaseDeclarationByIndex (int index)
{
    assert (index < bases_.size ());
    return bases_.at (index);
}

int ClassDeclaration::GetBasesCount ()
{
    return bases_.size ();
}

VariableDeclaration *ClassDeclaration::GetMemberDeclarationByIndex (int index)
{
    assert (index < members_.size ());
    return members_.at (index);
}

int ClassDeclaration::GetMembersCount ()
{
    return members_.size ();
}

FunctionDeclaration *ClassDeclaration::GetFunctionDeclarationByIndex (int index)
{
    assert (index < functions_.size ());
    return functions_.at (index);
}

int ClassDeclaration::GetFunctionsCount ()
{
    return functions_.size ();
}

std::string ClassDeclaration::GetName ()
{
    return name_;
}

std::string ClassDeclaration::GetType ()
{
    return "Class";
}

std::string ClassDeclaration::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[class ";
    result += name_;

    if (bases_.size () > 0)
    {
        result += " inherits from ";
        for (int index = 0; index < bases_.size (); index++)
        {
            result += bases_.at (index)->GetName ();
            if (index > bases_.size () - 1)
                result += ", ";
        }
    }

    result += ";\n" + indent + "members:\n";
    for (int index = 0; index < members_.size (); index++)
        result += members_.at (index)->ToString (addSpacesIndentation + 4) + "\n";

    result += "\n" + indent + "functions:\n";
    for (int index = 0; index < functions_.size (); index++)
        result += functions_.at (index)->ToString (addSpacesIndentation + 4) + "\n";
    result += "end of class declaration]";
    return result;
}
}
