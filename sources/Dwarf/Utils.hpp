#pragma once
#include <string>

#define DWARF_OBJECT_WITH_KNOWN_TYPE(typeName, typeNameHash) \
    public: \
        virtual std::string GetObjectTypeName () { return #typeName; } \
        virtual unsigned GetObjectTypeHash () { return typeNameHash; }

namespace Dwarf
{
enum VariableCreationType
{
    VARIABLE_LOCAL = 0,
    VARIABLE_GLOBAL = 1,
    VARIABLE_CLASS_MEMBER = 2
};

enum VariableConstructionType
{
    VARIABLE_CONSTRUCTION_NEW = 0,
    VARIABLE_CONSTRUCTION_COPY = 1,
    VARIABLE_CONSTRUCTION_REF = 2
};

std::string IntToString (int number);
std::string FloatToString (float number);
std::string DoubleToString (double number);
unsigned StringToHash(std::string str);

class StringifyAble
{
public:
    virtual std::string ToString (int addSpacesIndentation = 0) = 0;
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

class Range
{
public:
    double minimum_;
    double maximum_;
    double step_;

    Range (double minimum, double maximum, double step = 1.0);
    virtual ~Range ();
};
}
