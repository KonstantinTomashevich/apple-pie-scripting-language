#pragma once
#include <vector>
#include "TokenData.hpp"

namespace ApplePie
{
const char CONTINUE_LINE_CHAR = '@';
const char COMMENT_START_CHAR = '#';
const char CODE_BLOCK_START_CHAR = '{';
const char CODE_BLOCK_END_CHAR = '}';

const char LINE_END_CHAR = '\n';
const char OBJECT_ACCESS_CHAR = '.';
const char OPEN_CIRCLE_BRACKET_CHAR = '(';
const char CLOSE_CIRCLE_BRACKET_CHAR = ')';

const char OPEN_QUAD_BRACKET_CHAR = '[';
const char CLOSE_QUAD_BRACKET_CHAR = ']';
const char STRING_LITERAL_START_END_CHAR = '\"';
const char STRING_LITERAL_ADD_QUOTE_SYMBOL_CHAR = '\\';

class Lexer
{
protected:
    int lastReadIndex_;
    std::string processingCode_;
    // For logs where error is found.
    int lastLineIndex_;

    bool SkipComment();
    void SkipSpaces ();
    bool ReadIdentifier (std::vector <TokenData> &tokens);
    bool ReadNumber (std::vector <TokenData> &tokens);
    bool ReadString (std::vector <TokenData> &tokens);
    bool ReadNotAlNumSymbols (std::vector <TokenData> &tokens);
public:
    Lexer ();
    virtual ~Lexer ();
    std::vector <TokenData> Process (std::string code);
};
}
