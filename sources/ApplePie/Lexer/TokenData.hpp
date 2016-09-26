#pragma once
#include <string>

namespace ApplePie
{
enum TokenType
{
    // ApplePie reads '\n' as ';' in C++. If you want to skip next '\n' add '\' before end of line.
    TOKEN_END_OF_LINE = 1,

    // Special command for defining functions.
    TOKEN_DEFINE_COMMAND = 2,

    // 'myfunc', 'var1'...
    TOKEN_IDENTIFIER = 3,
    // '3.45', '4', '.5'...
    TOKEN_NUMBER_LITERAL = 4,
    // '+', '=', '&&'...
    TOKEN_NOT_ALNUM_SYMBOLS = 5,

    // End of input string.
    TOKEN_END_OF_INPUT = 6
};

class TokenData
{
public:
    TokenData ();
    TokenData (TokenType type, std::string additionalDataStr = "", double additionalDataDouble = 0.0);
    virtual ~TokenData ();

    TokenType type_;
    double additionalDataDouble_;
    std::string additionalDataStr_;
};
}
