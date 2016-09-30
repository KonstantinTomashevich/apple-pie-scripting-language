#pragma once
#include <string>

namespace ApplePie
{
enum TokenType
{
    // ApplePie reads '\n' as ';' in C++. If you want to skip next '\n' add '@' before end of line.
    TOKEN_END_OF_LINE = 1,

    // 'myfunc', 'var1'...
    TOKEN_IDENTIFIER,
    // '3.45', '4', '.5'...
    TOKEN_NUMERIC_LITERAL,
    // '"mystring"'...
    TOKEN_STRING_LITERAL,
    // '+', '=', '&&'...
    TOKEN_NOT_ALNUM_SYMBOLS,

    // For declaring local variables.
    TOKEN_LOCAL,
    // For declaring global variables.
    TOKEN_GLOBAL,
    // For declaring class members.
    TOKEN_MEMBER,
    // For declaring functions.
    TOKEN_DEFINE,
    // For declaring classes.
    TOKEN_CLASS,
    // For declaring class bases.
    TOKEN_INHERITS,

    // '{'
    TOKEN_CODE_BLOCK_START,
    // '}'
    TOKEN_CODE_BLOCK_END,
    // Object members of functions of static class members access
    TOKEN_OBJECT_ACCESS,

    // '('
    TOKEN_OPEN_CIRCLE_BRACKET,
    // ')'
    TOKEN_CLOSE_CIRCLE_BRACKET,

    // '['
    TOKEN_OPEN_QUAD_BRACKET,
    // ']'
    TOKEN_CLOSE_QUAD_BRACKET,

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
