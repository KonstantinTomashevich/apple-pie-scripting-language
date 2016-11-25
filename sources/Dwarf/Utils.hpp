#pragma once
#include <string>

#define DWARF_OBJECT_WITH_KNOWN_TYPE(typeName, typeNameHash) \
    public: \
        virtual std::string GetObjectTypeName () { return #typeName; } \
        virtual unsigned GetObjectTypeHash () { return typeNameHash; }

// TODO: Not about utils. About language at all. See next lines.
// Maybe don't use Scala-style of objects constructors? Maybe it better to use default for almost all languages style?
// Something like this:
//class OurClass : BaseA, BaseB
//{
//    ...
//    members
//    ...
//
//    construction (Arg1 : Type1, Arg2 : Type2) : BaseA (Arg1), BaseB (Arg2)
//    {
//
//    }
//
//    destruction
//    {
//
//    }
//
//    ...
//    functions
//    ...
//}

// TODO: For future. See next lines.
// What about easier objects and classes handling?

// Class can be something like:
// bases -- std::vector
// constructor -- function with arguments (returnContainer : Ptr, arguments : Vector)
// destructor -- function with arguments (thisObject : ObjectPtr)
// functions -- array of pointers to functions with arguments (thisObject : ObjectPtr, returnContainer : Ptr, arguments : Vector).

// Object can be something like:
// class -- pointer to Class
// cxxRepresentation -- void pointer
// scriptObjectMembers -- std::vector of Objects'
// refsCount -- count of refs to object

// TODO: Another notes about bytecode (for future). See next lines.
// Maybe don't implement classes and object mechanism in bytecode?
// We can define some basic types.
// For example: Number, FixedArray, DynamicArray, Map.
// And internal class Structure (or HashTable, this name describes more) for objects.
// Structures' will contain members or object, array of base classes (such as classes in Lua).
// And pointer to C++ object for C++-side classes, ofcourse.
// Functions of classes will be defined as global functions.
// With this, implementations of namespaces look easy too.
// Because any object name will be hash of something like "namespace1.namespace2.Class1.functionName".
// (Except class members, they will be only "memberName", because they will be in Structures'.
// With all of this, bytecode interprter will not know about classes, namespaces and many other hard-to-implement features. :)

namespace Dwarf
{
// TODO: If variable created inside function, it will be local (obviously). /...Continued.../
// If variable created outside functions and classes, it will be global (obviously too).
// And that seems that we don't need "VariableCreationType", we need only isClassMember flag.
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
// TODO: Maybe adopt string hashing algorithm from Urho3D? It will be much more reliable.
// TODO: But hashes of different strings still equal in very small percent of situations. It's ok for now, but I think it will be rewrited in the future.
unsigned long StringToHash (std::string str);

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
