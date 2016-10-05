#include "AstClass.hpp"
#include <assert.h>
#include <ApplePie/AST/AstCreateVariable.hpp>

namespace ApplePie
{
void AstClass::GenerateDeclaration ()
{
    std::vector <std::string> basesNames;
    if (!basesConstructorsCalls_.empty ())
        for (int index = 0; index < basesConstructorsCalls_.size (); index++)
            basesNames.push_back (basesConstructorsCalls_.at (index)->GetCalledFunctionName ());

    std::vector <VariableDeclaration *> members;
    if (constructor_->GetBody ()->GetValuesCount () > 0)
        for (int index = 0; index < constructor_->GetBody ()->GetValuesCount (); index++)
        {
            AstValue *value = constructor_->GetBody ()->GetValueByIndex (index);
            if (value->GetObjectTypeHash () == AST_CREATE_VARIABLE_TYPE_HASH &&
                    ((AstCreateVariable *) value)->GetCreationType () == VARIABLE_CLASS_MEMBER)
            {
                AstCreateVariable *createVariableValue = (AstCreateVariable *) value;
                VariableDeclaration *declaration = new VariableDeclaration (
                            createVariableValue->GetDeclaration ()->GetName (),
                            createVariableValue->GetDeclaration ()->GetType ());
                members.push_back (declaration);
            }
        }

    std::vector <FunctionDeclaration *> functionsDeclarations;
    if (!functions_.empty ())
        for (int index = 0; index < functions_.size (); index++)
        {
            AstFunction *function = functions_.at (index);

            std::vector <VariableDeclaration *> arguments;
            for (int argumentIndex = 0; argumentIndex < function->GetDeclaration ()->GetArgumentsCount (); argumentIndex++)
            {
                VariableDeclaration *argumentDecl = function->GetDeclaration ()->GetArgumentDeclarationByIndex (argumentIndex);
                VariableDeclaration *copy = new VariableDeclaration (
                            argumentDecl->GetName (),
                            argumentDecl->GetType ());
                arguments.push_back (copy);
            }

            FunctionDeclaration *declaration = new FunctionDeclaration (
                        function->GetDeclaration ()->GetName (),
                        function->GetDeclaration ()->GetReturnType (),
                        arguments);
            functionsDeclarations.push_back (declaration);
        }

    generatedDeclaration_ = new ClassDeclaration (name_, basesNames, members, functionsDeclarations);
}

AstClass::AstClass (std::string name, std::vector <AstCall *> basesConstructorsCalls,
                    AstFunction *constructor, std::vector <AstFunction *> functions) :
    name_ (name),
    basesConstructorsCalls_ (basesConstructorsCalls),
    constructor_ (constructor),
    functions_ (functions),
    generatedDeclaration_ (0)
{
    assert (!name_.empty ());
    assert (constructor_);
    GenerateDeclaration ();
}

AstClass::~AstClass ()
{
    if (!basesConstructorsCalls_.empty ())
        for (int index = 0; index < basesConstructorsCalls_.size (); index++)
            delete basesConstructorsCalls_.at (index);
    basesConstructorsCalls_.clear ();

    if (!functions_.empty ())
        for (int index = 0; index < functions_.size (); index++)
            delete functions_.at (index);
    functions_.clear ();

    delete constructor_;
    delete generatedDeclaration_;
}

std::string AstClass::GetName ()
{
    return name_;
}

AstCall *AstClass::GetBaseConstructorCallByIndex (int index)
{
    assert (index < basesConstructorsCalls_.size ());
    return basesConstructorsCalls_.at (index);
}

int AstClass::GetBasesConstructorsCallsCount ()
{
    return basesConstructorsCalls_.size ();
}

AstFunction *AstClass::GetConstructor ()
{
    return constructor_;
}

AstFunction *AstClass::GetFunctionByIndex (int index)
{
    assert (index < functions_.size ());
    return functions_.at (index);
}

int AstClass::GetFunctionsCount ()
{
    return functions_.size ();
}

ClassDeclaration *AstClass::GetGeneratedDeclaration ()
{
    return generatedDeclaration_;
}

std::string AstClass::ToString (int addSpacesIndentation)
{
    std::string result = "";
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[class value ";
    result += name_;
    result += ";\n" + indent + "declaration:\n";
    result += generatedDeclaration_->ToString (addSpacesIndentation + 4) + "\n";

    result += indent + "bases constructors calls:\n";
    if (!basesConstructorsCalls_.empty ())
        for (int index = 0; index < basesConstructorsCalls_.size (); index++)
            result += basesConstructorsCalls_.at (index)->ToString (addSpacesIndentation + 4) + "\n";

    result += indent + "constructor:\n";
    result += constructor_->ToString (addSpacesIndentation + 4) + "\n";

    result += indent + "functions:\n";
    if (!functions_.empty ())
        for (int index = 0; index < functions_.size (); index++)
            result += functions_.at (index)->ToString (addSpacesIndentation + 4) + "\n";

    result += indent + "end of class value]";
    return result;
}
}
