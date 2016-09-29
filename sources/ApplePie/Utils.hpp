#pragma once
#include <string>

#define APPLE_PIE_OBJECT_WITH_KNOWN_TYPE(typeName, typeNameHash) \
    public: \
        virtual std::string GetObjectTypeName () { return #typeName; } \
        virtual unsigned GetObjectTypeHash () { return typeNameHash; }

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
