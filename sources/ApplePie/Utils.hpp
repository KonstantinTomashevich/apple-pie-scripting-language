#pragma once
#include <string>

namespace ApplePie
{
class StringifyAble
{
public:
    virtual std::string ToString () = 0;
};

class ObjectWithKnownType
{
public:
    virtual std::string GetObjectTypeName () = 0;
};
}
