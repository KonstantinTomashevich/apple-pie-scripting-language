#include "PackageDeclaration.hpp"
#include <assert.h>

namespace Dwarf
{

PackageDeclaration::PackageDeclaration (std::string name, std::vector<Declaration *> declarationsInside) :
    name_ (name),
    declarationsInside_ (declarationsInside)
{

}

PackageDeclaration::~PackageDeclaration ()
{
    if (!declarationsInside_.empty ())
        for (int index = 0; index < declarationsInside_.size (); index++)
            delete declarationsInside_.at (index);
    declarationsInside_.clear ();
}

Declaration *PackageDeclaration::GetDeclarationByIndex (int index)
{
    assert (index < declarationsInside_.size ());
    return declarationsInside_.at (index);
}

int PackageDeclaration::GetDeclarationsCount ()
{
    return declarationsInside_.size ();
}

std::string PackageDeclaration::GetName ()
{
    return name_;
}

std::string PackageDeclaration::GetType ()
{
    return "Package";
}

std::string PackageDeclaration::ToString (int addSpacesIndentation)
{
    std::string result;
    std::string indent = "";
    if (addSpacesIndentation > 0)
        for (int index = 0; index < addSpacesIndentation; index++)
            indent += " ";

    result += indent + "[package " + name_ + "; content:\n";
    for (int index = 0; index < declarationsInside_.size (); index++)
        result += declarationsInside_.at (index)->ToString (addSpacesIndentation + 4) + "\n";

    result += indent + "end of package " + name_ + "]";
    return result;
}
}
