#include "Lexer.hpp"
#include "assert.h"
#include <string>
#include <iostream>

namespace ApplePie
{
void Lexer::SkipComment ()
{
    assert (processingCode_.at (lastReadIndex_) == COMMENT_START_CHAR);
    do
    {
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
            return;
    }
    while (processingCode_.at (lastReadIndex_) != LINE_END_CHAR);
    lastReadIndex_ += 1;
}

void Lexer::SkipSpaces ()
{
    assert (std::isspace (processingCode_.at (lastReadIndex_)));
    do
    {
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
            return;
    }
    while (std::isspace (processingCode_.at (lastReadIndex_)));
    lastReadIndex_ += 1;
}

void Lexer::ReadIdentifier (std::vector<TokenData> &tokens)
{
    assert (std::isalpha (processingCode_.at (lastReadIndex_)));
    std::string identifier = "";
    do
    {
        identifier += processingCode_.at (lastReadIndex_);
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_IDENTIFIER, identifier));
            return;
        }
    }
    while (std::isalnum (processingCode_.at (lastReadIndex_)));
    tokens.push_back (TokenData (TOKEN_IDENTIFIER, identifier));
    lastReadIndex_ += 1;
}

void Lexer::ReadNumber (std::vector<TokenData> &tokens)
{
    assert (std::isdigit (processingCode_.at (lastReadIndex_)) || processingCode_.at (lastReadIndex_) == '.');
    std::string number = "";
    do
    {
        number += processingCode_.at (lastReadIndex_);
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_NUMBER_LITERAL, "", atof (number.c_str ())));
            return;
        }
    }
    while (std::isalnum (processingCode_.at (lastReadIndex_)));
    tokens.push_back (TokenData (TOKEN_NUMBER_LITERAL, "", atof (number.c_str ())));
    lastReadIndex_ += 1;
}

void Lexer::ReadNotAlNumSymbols (std::vector<TokenData> &tokens)
{
    assert (!std::isalnum (processingCode_.at (lastReadIndex_)));
    assert (processingCode_.at (lastReadIndex_) != CONTINUE_LINE_CHAR);
    assert (processingCode_.at (lastReadIndex_) != LINE_END_CHAR);
    assert (processingCode_.at (lastReadIndex_) != CODE_BLOCK_START_CHAR);
    assert (processingCode_.at (lastReadIndex_) != CODE_BLOCK_END_CHAR);

    std::string symbols = "";
    do
    {
        symbols += processingCode_.at (lastReadIndex_);
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_NOT_ALNUM_SYMBOLS, symbols);
            return;
        }
    }
    while (!std::isalnum (processingCode_.at (lastReadIndex_)) &&
           processingCode_.at (lastReadIndex_) != CONTINUE_LINE_CHAR &&
           processingCode_.at (lastReadIndex_) != LINE_END_CHAR &&
           processingCode_.at (lastReadIndex_) != CODE_BLOCK_START_CHAR &&
           processingCode_.at (lastReadIndex_) != CODE_BLOCK_END_CHAR);
    lastReadIndex_ += 1;
}

Lexer::Lexer ()
{

}

Lexer::~Lexer ()
{

}

std::vector <TokenData> Lexer::Process (std::string code)
{
    // Clear lexer data
    lastReadIndex_ = 0;
    lastLineIndex_ = 1;
    lastCharIndex_ = 1;
    processingCode_ = code;

    // Read tokens
    std::vector <TokenData> tokens;
    while (lastReadIndex_ < processingCode_.length ())
    {
        if (processingCode_.at (lastReadIndex_) == COMMENT_START_CHAR)
            SkipComment ();

        else if (std::isspace (processingCode_.at (lastReadIndex_)))
            SkipSpaces ();

        else if (std::isalpha (processingCode_.at (lastReadIndex_)))
            ReadIdentifier (tokens);

        else if (std::isdigit (processingCode_.at (lastReadIndex_)) || processingCode_.at (lastReadIndex_) == '.')
            ReadNumber (tokens);

        else if (processingCode_.at (lastReadIndex_) == CODE_BLOCK_START_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_CODE_BLOCK_START));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == CODE_BLOCK_END_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_CODE_BLOCK_END));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == CONTINUE_LINE_CHAR)
        {
            lastReadIndex_ += 1;
            if (processingCode_.at (lastReadIndex_) != LINE_END_CHAR)
            {
                std::cerr << "Lexer error: expected '\n' after '\\', but got '" << processingCode_.at (lastReadIndex_) << "'!";
                return std::vector <TokenData> ();
            }
            lastReadIndex_ += 1;
        }

        else
            ReadNotAlNumSymbols (tokens);
    }

    tokens.push_back (TokenData (TOKEN_END_OF_INPUT));
    // Clear lexer data
    lastReadIndex_ = 0;
    lastLineIndex_ = 1;
    lastCharIndex_ = 1;
    processingCode_ = "";
    return tokens;
}
}

