#include "TokenData.hpp"

namespace ApplePie
{
TokenData::TokenData ()
{

}

TokenData::TokenData (TokenType type, std::string additionalDataStr, double additionalDataDouble, int lineIndex) :
    type_ (type),
    additionalDataStr_ (additionalDataStr),
    additionalDataDouble_ (additionalDataDouble),
    lineIndex_ (lineIndex)
{

}

TokenData::~TokenData ()
{

}
}

