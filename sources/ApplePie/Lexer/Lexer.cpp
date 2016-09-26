#include "Lexer.hpp"
#include "assert.h"
#include <string>
#include <iostream>

namespace ApplePie
{
bool Lexer::SkipComment ()
{
    assert (processingCode_.at (lastReadIndex_) == COMMENT_START_CHAR);
    do
    {
        lastReadIndex_ += 1;

        if (processingCode_.at (lastReadIndex_) == CONTINUE_LINE_CHAR)
        {
            lastReadIndex_ += 1;
            if (processingCode_.at (lastReadIndex_) != LINE_END_CHAR)
            {
                std::cout << "ERROR: expected '\n' after '@', but got '" << processingCode_.at (lastReadIndex_) << "'!";
                return false;
            }
            lastReadIndex_ += 1;
            lastLineIndex_ += 1;
        }

        if (lastReadIndex_ >= processingCode_.length ())
            return true;
    }
    while (processingCode_.at (lastReadIndex_) != LINE_END_CHAR);
    lastLineIndex_ += 1;
    lastReadIndex_ += 1;
    return true;
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
}

bool Lexer::ReadIdentifier (std::vector <TokenData> &tokens)
{
    assert (std::isalpha (processingCode_.at (lastReadIndex_)));
    std::string identifier = "";
    do
    {
        identifier += processingCode_.at (lastReadIndex_);
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_IDENTIFIER, identifier, 0.0, lastLineIndex_));
            return true;
        }
    }
    while (std::isalnum (processingCode_.at (lastReadIndex_)));
    tokens.push_back (TokenData (TOKEN_IDENTIFIER, identifier, 0.0, lastLineIndex_));
    return true;
}

bool Lexer::ReadNumber (std::vector <TokenData> &tokens)
{
    assert (std::isdigit (processingCode_.at (lastReadIndex_)));
    std::string number = "";
    do
    {
        number += processingCode_.at (lastReadIndex_);
        lastReadIndex_ += 1;

        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_NUMBER_LITERAL, number, atof (number.c_str ()), lastLineIndex_));
            return true;
        }
    }
    while (std::isdigit (processingCode_.at (lastReadIndex_)) || processingCode_.at (lastReadIndex_) == '.');
    tokens.push_back (TokenData (TOKEN_NUMBER_LITERAL, number, atof (number.c_str ()), lastLineIndex_));
    return true;
}

bool Lexer::ReadString (std::vector <TokenData> &tokens)
{
    assert (processingCode_.at (lastReadIndex_) == STRING_LITERAL_START_END_CHAR);
    std::string stringLiteral = "";
    bool isSkipNextQuote = false;

    do
    {
        if (processingCode_.at (lastReadIndex_) == STRING_LITERAL_ADD_QUOTE_SYMBOL_CHAR)
        {
            if (lastReadIndex_ + 1 >= processingCode_.length ())
            {
                std::cout << "ERROR: Line " << lastLineIndex_ << ". '\\' at the end of input!";
                return false;
            }

            if (processingCode_.at (lastReadIndex_ + 1) == 'n')
            {
                stringLiteral += '\n';
                lastReadIndex_ += 1;
            }
            else if (!isSkipNextQuote)
                isSkipNextQuote = true;
            else
            {
                stringLiteral += STRING_LITERAL_ADD_QUOTE_SYMBOL_CHAR;
                isSkipNextQuote = false;
            }
        }

        else if (processingCode_.at (lastReadIndex_) == LINE_END_CHAR)
        {
            std::cout << "ERROR: Line " << lastLineIndex_ << ". Expected '\"', but got '\\n'!";
            return false;
        }

        else if (processingCode_.at (lastReadIndex_) == CONTINUE_LINE_CHAR)
        {
            lastReadIndex_ += 1;
            if (isSkipNextQuote)
                stringLiteral += CONTINUE_LINE_CHAR;
            else if (processingCode_.at (lastReadIndex_) != LINE_END_CHAR)
            {
                std::cout << "ERROR: expected '\n' after '@', but got '" << processingCode_.at (lastReadIndex_) << "'!";
                return false;
            }
            else
                lastLineIndex_ += 1;
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == STRING_LITERAL_START_END_CHAR)
        {
            if (isSkipNextQuote)
                stringLiteral += STRING_LITERAL_START_END_CHAR;
        }
        else
            stringLiteral += processingCode_.at (lastReadIndex_);

        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_STRING_LITERAL, stringLiteral, 0.0, lastLineIndex_));
            return true;
        }
        lastReadIndex_ += 1;
    }
    while (processingCode_.at (lastReadIndex_) != STRING_LITERAL_START_END_CHAR || isSkipNextQuote);
    tokens.push_back (TokenData (TOKEN_STRING_LITERAL, stringLiteral, 0.0, lastLineIndex_));
    lastReadIndex_ += 1;
    return true;
}

bool Lexer::ReadNotAlNumSymbols (std::vector <TokenData> &tokens)
{
    assert (!std::isalnum (processingCode_.at (lastReadIndex_)));
    assert (!std::isspace (processingCode_.at (lastReadIndex_)));
    assert (processingCode_.at (lastReadIndex_) != CONTINUE_LINE_CHAR);
    assert (processingCode_.at (lastReadIndex_) != LINE_END_CHAR);
    assert (processingCode_.at (lastReadIndex_) != CODE_BLOCK_START_CHAR);
    assert (processingCode_.at (lastReadIndex_) != CODE_BLOCK_END_CHAR);
    assert (processingCode_.at (lastReadIndex_) != OBJECT_ACCESS_CHAR);

    std::string symbols = "";
    do
    {
        symbols += processingCode_.at (lastReadIndex_);
        lastReadIndex_ += 1;
        if (lastReadIndex_ >= processingCode_.length ())
        {
            tokens.push_back (TokenData (TOKEN_NOT_ALNUM_SYMBOLS, symbols, 0.0, lastLineIndex_));
            return true;
        }
    }
    while (!std::isalnum (processingCode_.at (lastReadIndex_)) &&
           !std::isspace (processingCode_.at (lastReadIndex_)) &&
           processingCode_.at (lastReadIndex_) != CONTINUE_LINE_CHAR &&
           processingCode_.at (lastReadIndex_) != LINE_END_CHAR &&
           processingCode_.at (lastReadIndex_) != CODE_BLOCK_START_CHAR &&
           processingCode_.at (lastReadIndex_) != CODE_BLOCK_END_CHAR &&
           processingCode_.at (lastReadIndex_) != OBJECT_ACCESS_CHAR);

    tokens.push_back (TokenData (TOKEN_NOT_ALNUM_SYMBOLS, symbols, 0.0, lastLineIndex_));
    return true;
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
    processingCode_ = code;

    // Read tokens
    std::vector <TokenData> tokens;
    while (lastReadIndex_ < processingCode_.length ())
    {
        if (processingCode_.at (lastReadIndex_) == LINE_END_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_END_OF_LINE, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
            lastLineIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == COMMENT_START_CHAR)
        {
            if (!SkipComment ())
                return std::vector <TokenData> ();
        }

        else if (std::isspace (processingCode_.at (lastReadIndex_)))
            SkipSpaces ();

        else if (std::isalpha (processingCode_.at (lastReadIndex_)))
        {
            if (!ReadIdentifier (tokens))
                return std::vector <TokenData> ();
        }

        else if (std::isdigit (processingCode_.at (lastReadIndex_)))
        {
            if (!ReadNumber (tokens))
                return std::vector <TokenData> ();
        }

        else if (processingCode_.at (lastReadIndex_) == CODE_BLOCK_START_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_CODE_BLOCK_START, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == CODE_BLOCK_END_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_CODE_BLOCK_END, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == OBJECT_ACCESS_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_OBJECT_ACCESS, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == OPEN_CIRCLE_BRACKET_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_OPEN_CIRCLE_BRACKET, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == CLOSE_CIRCLE_BRACKET_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_CLOSE_CIRCLE_BRACKET, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == OPEN_QUAD_BRACKET_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_OPEN_QUAD_BRACKET, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == CLOSE_QUAD_BRACKET_CHAR)
        {
            tokens.push_back (TokenData (TOKEN_CLOSE_QUAD_BRACKET, "", 0.0, lastLineIndex_));
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == CONTINUE_LINE_CHAR)
        {
            lastReadIndex_ += 1;
            if (processingCode_.at (lastReadIndex_) != LINE_END_CHAR)
            {
                std::cout << "ERROR: expected '\n' after '@', but got '" << processingCode_.at (lastReadIndex_) << "'!";
                return std::vector <TokenData> ();
            }
            lastReadIndex_ += 1;
        }

        else if (processingCode_.at (lastReadIndex_) == STRING_LITERAL_START_END_CHAR)
        {
            if (!ReadString (tokens))
                return std::vector <TokenData> ();
        }

        else
        {
            if (!ReadNotAlNumSymbols (tokens))
                return std::vector <TokenData> ();
        }
    }

    tokens.push_back (TokenData (TOKEN_END_OF_INPUT, "", 0.0, lastLineIndex_ + 1));
    // Clear lexer data
    lastReadIndex_ = 0;
    lastLineIndex_ = 1;
    processingCode_ = "";
    return tokens;
}
}

