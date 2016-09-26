#pragma once
#include <string>

namespace ApplePie
{
enum TokenType
{
    // ApplePie reads '\n' as ';' in C++. If you want to skip next '\n' add '\' before end of line.
    TOKEN_END_OF_LINE = 1,

    // 'myfunc', 'var1'...
    TOKEN_IDENTIFIER = 2,
    // '3.45', '4', '.5'...
    TOKEN_NUMBER_LITERAL = 3,
    // '+', '=', '&&'...
    TOKEN_NOT_ALNUM_SYMBOLS = 4,

    // '{'
    TOKEN_CODE_BLOCK_START = 5,
    // '}'
    TOKEN_CODE_BLOCK_END = 6,

    // End of input string.
    TOKEN_END_OF_INPUT = -1
};

class TokenData
{
public:
    TokenData ();
    TokenData (TokenType type, std::string additionalDataStr = "", double additionalDataDouble = 0.0,
               int lineIndex = -1, int characterOnLineIndex = -1);
    virtual ~TokenData ();

    TokenType type_;
    double additionalDataDouble_;
    std::string additionalDataStr_;

    int lineIndex_;
    int characterOnLineIndex_;
};
}
