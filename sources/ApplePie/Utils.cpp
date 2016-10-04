#include "Utils.hpp"
#include <sstream>

namespace ApplePie
{
unsigned StringToHash (std::string str)
{
    unsigned hash = 37;
    for (int index = 0; index < str.length (); index++)
        hash = (hash * 54059) ^ (str.at (index) * 76943);
    return hash % 86969;
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

std::string IntToString (int number)
{
    std::stringstream strs;
    strs << number;
    return strs.str ();
}

std::string FloatToString (float number)
{
    std::stringstream strs;
    strs << number;
    return strs.str ();
}

std::string DoubleToString (double number)
{
    std::stringstream strs;
    strs << number;
    return strs.str ();
}

Range::Range (double minimum, double maximum, double step) :
    minimum_ (minimum),
    maximum_ (maximum),
    step_ (step)
{

}

Range::~Range()
{

}
}
