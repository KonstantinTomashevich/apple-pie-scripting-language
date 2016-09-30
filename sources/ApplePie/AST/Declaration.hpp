#pragma once
#include <ApplePie/Utils.hpp>

namespace ApplePie
{
class Declaration : public StringifyAble, public ObjectWithKnownType
{
public:
    virtual std::string GetName () = 0;
    virtual std::string GetType () = 0;
};
}
