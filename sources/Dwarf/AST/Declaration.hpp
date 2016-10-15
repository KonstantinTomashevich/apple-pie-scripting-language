#pragma once
#include <Dwarf/Utils.hpp>

namespace Dwarf
{
class Declaration : public StringifyAble, public ObjectWithKnownType
{
public:
    virtual std::string GetName () = 0;
    virtual std::string GetType () = 0;
};
}
