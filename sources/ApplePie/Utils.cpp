#include "Utils.hpp"
namespace ApplePie
{
unsigned StringToHash (std::string str)
{
    unsigned hash = 37;
    for (int index = 0; index < str.length (); index++)
        hash = (hash * 54059) ^ (str.at (index) * 76943);
    return hash % 86969;
}

ObjectWithKnownTypeImpl::ObjectWithKnownTypeImpl (std::string typeName) :
    typeName_ (typeName),
    typeHash_ (StringToHash (typeName))
{

}

ObjectWithKnownTypeImpl::~ObjectWithKnownTypeImpl ()
{

}

std::string ObjectWithKnownTypeImpl::GetObjectTypeName ()
{
    return typeName_;
}

unsigned ObjectWithKnownTypeImpl::GetObjectTypeHash ()
{
    return typeHash_;
}

RefCounted::RefCounted ()
{
    ignore_ = false;
    refsCount_ = 0;
}

RefCounted::~RefCounted ()
{

}

void RefCounted::AddRef ()
{
    refsCount_ += 1;
}

void RefCounted::ReleaseRef ()
{
    refsCount_ -= 1;
    if (refsCount_ < 1 && !ignore_)
        delete this;
}

bool RefCounted::IsIgnoringRefsCount ()
{
    return ignore_;
}

void RefCounted::SetIsIgnoringRefsCount (bool ignore)
{
    ignore_ = ignore;
}
}
