#pragma once
#include <string>

namespace ApplePie
{
unsigned StringToHash(std::string str);
class StringifyAble
{
public:
    virtual std::string ToString () = 0;
};

class ObjectWithKnownType
{
public:
    virtual std::string GetObjectTypeName () = 0;
    virtual unsigned GetObjectTypeHash () = 0;
};

class ObjectWithKnownTypeImpl : public ObjectWithKnownType
{
private:
    unsigned typeHash_;
    std::string typeName_;
public:
    ObjectWithKnownTypeImpl (std::string typeName);
    virtual ~ObjectWithKnownTypeImpl ();

    virtual std::string GetObjectTypeName ();
    virtual unsigned GetObjectTypeHash ();
};

class RefCounted
{
private:
    int refsCount_;
    bool ignore_;
public:
    RefCounted ();
    virtual ~RefCounted ();

    void AddRef ();
    void ReleaseRef ();

    bool IsIgnoringRefsCount ();
    void SetIsIgnoringRefsCount (bool ignore);
};
}
