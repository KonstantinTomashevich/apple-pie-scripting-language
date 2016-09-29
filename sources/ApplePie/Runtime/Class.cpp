#include "Class.hpp"

namespace ApplePie
{
std::map <unsigned, Object *> *Class::GetMembersMap (Object *object)
{
    return &object->members_;
}

void Class::SetThisAsObjectType (Object *object)
{
    object->type_ = this;
}

Class::Class ()
{

}

Class::~Class ()
{

}
}

