#pragma once
#include <string>

namespace ApplePie
{
enum TokenType
{
    // ApplePie reads '\n' as ';' in C++. If you want to skip next '\n' add '@' before end of line.
    TOKEN_END_OF_LINE = 1,

    // 'myfunc', 'var1'...
    TOKEN_IDENTIFIER = 2,
    // '3.45', '4', '.5'...
    TOKEN_NUMERIC_LITERAL = 3,
    // '"mystring"'...
    TOKEN_STRING_LITERAL = 4,
    // '+', '=', '&&'...
    TOKEN_NOT_ALNUM_SYMBOLS = 5,

    // For declaring local variables.
    TOKEN_LOCAL = 6,
    // For declaring global variables.
    TOKEN_GLOBAL = 7,
    // For declaring functions.
    TOKEN_DEFINE = 8,
    // For declaring classes.
    TOKEN_CLASS = 9,

    // '{'
    TOKEN_CODE_BLOCK_START = 10,
    // '}'
    TOKEN_CODE_BLOCK_END = 11,
    // Object members of functions of static class members access
    TOKEN_OBJECT_ACCESS = 12,

    // '('
    TOKEN_OPEN_CIRCLE_BRACKET = 13,
    // ')'
    TOKEN_CLOSE_CIRCLE_BRACKET = 14,

    // '['
    TOKEN_OPEN_QUAD_BRACKET = 15,
    // ']'
    TOKEN_CLOSE_QUAD_BRACKET = 16,

    // End of input string.
    TOKEN_END_OF_INPUT = -1
};

class TokenData
{
public:
    TokenData ();
    TokenData (TokenType type, std::string additionalDataStr = "", double additionalDataDouble = 0.0, int lineIndex = -1);
    virtual ~TokenData ();

    TokenType type_;
    double additionalDataDouble_;
    std::string additionalDataStr_;
    int lineIndex_;
};
}
