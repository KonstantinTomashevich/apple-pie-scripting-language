#include "TokenData.hpp"

namespace ApplePie
{
TokenData::TokenData ()
{

}

TokenData::TokenData (TokenType type, std::string additionalDataStr, double additionalDataDouble) :
    type_ (type),
    additionalDataStr_ (additionalDataStr),
    additionalDataDouble_ (additionalDataDouble)
{

}

TokenData::~TokenData ()
{

}
}

