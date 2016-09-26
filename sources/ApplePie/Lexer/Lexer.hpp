#pragma once
#include <vector>
#include "TokenData.hpp"

namespace ApplePie
{
const char CONTINUE_LINE_CHAR = '\\';
const char COMMENT_START_CHAR = '#';
const char CODE_BLOCK_START_CHAR = '{';
const char CODE_BLOCK_END_CHAR = '}';
const char LINE_END_CHAR = '\n';

class Lexer
{
protected:
    int lastReadIndex_;
    std::string processingCode_;
    // For logs where error is found.
    int lastLineIndex_;
    int lastCharIndex_;

    void SkipComment ();
    void SkipSpaces ();
    void ReadIdentifier (std::vector <TokenData> &tokens);
    void ReadNumber (std::vector <TokenData> &tokens);
    void ReadNotAlNumSymbols (std::vector <TokenData> &tokens);
public:
    Lexer ();
    virtual ~Lexer ();
    std::vector <TokenData> Process (std::string code);
};
}
