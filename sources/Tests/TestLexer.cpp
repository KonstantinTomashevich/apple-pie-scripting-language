#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Defines.hpp"
#include <ApplePie/Lexer/Lexer.hpp>

std::string IntToString (int number)
{
    std::stringstream strs;
    strs << number;
    return strs.str ();
}

std::string TokenDataToString (ApplePie::TokenData tokenData)
{
    if (tokenData.type_ == ApplePie::TOKEN_END_OF_LINE)
        return "END_OF_LINE";

    else if (tokenData.type_ == ApplePie::TOKEN_IDENTIFIER)
        return "IDENTIFIER '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == ApplePie::TOKEN_NUMERIC_LITERAL)
        return "NUMBER '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == ApplePie::TOKEN_STRING_LITERAL)
        return "STRING '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == ApplePie::TOKEN_NOT_ALNUM_SYMBOLS)
        return "NOT_ALNUM_SYMBOLS '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == ApplePie::TOKEN_LOCAL)
        return "LOCAL";

    else if (tokenData.type_ == ApplePie::TOKEN_GLOBAL)
        return "GLOBAL";

    else if (tokenData.type_ == ApplePie::TOKEN_MEMBER)
        return "MEMBER";

    else if (tokenData.type_ == ApplePie::TOKEN_DEFINE)
        return "DEFINE";

    else if (tokenData.type_ == ApplePie::TOKEN_CLASS)
        return "CLASS";

    else if (tokenData.type_ == ApplePie::TOKEN_INHERITS)
        return "INHERITS";

    else if (tokenData.type_ == ApplePie::TOKEN_CODE_BLOCK_START)
        return "CODE_BLOCK_START";

    else if (tokenData.type_ == ApplePie::TOKEN_CODE_BLOCK_END)
        return "CODE_BLOCK_END";

    else if (tokenData.type_ == ApplePie::TOKEN_OBJECT_ACCESS)
        return "OBJECT_ACESS";

    else if (tokenData.type_ == ApplePie::TOKEN_OPEN_CIRCLE_BRACKET)
        return "OPEN_CIRCLE_BRACKETS";

    else if (tokenData.type_ == ApplePie::TOKEN_CLOSE_CIRCLE_BRACKET)
        return "CLOSE_CIRCLE_BRACKETS";

    else if (tokenData.type_ == ApplePie::TOKEN_OPEN_QUAD_BRACKET)
        return "OPEN_QUAD_BRACKETS";

    else if (tokenData.type_ == ApplePie::TOKEN_CLOSE_QUAD_BRACKET)
        return "CLOSE_QUAD_BRACKETS";

    else if (tokenData.type_ == ApplePie::TOKEN_END_OF_INPUT)
         return "END_OF_INPUT";

    else
        return "UNKNOWN TOKEN";
}

int main (int argsCount, char *args [])
{
    std::cout << "Reading test code...";
    std::ifstream file;
    std::string path;
    path += APPLE_PIE_TESTS_DATA_DIR;
    path += "/examples/for_testing/ForLexerTest.pie";
    file.open (path.c_str ());

    std::string code;
    std::string line;
    while (std::getline (file, line))
        code += line + '\n';
    file.close ();
    std::cout << "done.\n\n" << code;

    // TODO: Make some changes in test code. Variables construction syntax is [creationType] [name] : [type] ([arguments...]).

    ApplePie::Lexer lexer;
    std::vector <ApplePie::TokenData> tokens = lexer.Process (code);
    std::cout << "\n\nTokens count -- " << tokens.size () << ". Tokens:\n\n";

    std::string resultTokens = "";
    for (int index = 0; index < tokens.size (); index++)
    {
        resultTokens += IntToString (index);
        resultTokens += ": Line ";
        resultTokens += IntToString (tokens.at (index).lineIndex_);
        resultTokens += " -- ";
        resultTokens += TokenDataToString (tokens.at (index));
        resultTokens += "\n";
    }
    std::cout << resultTokens;

    path = APPLE_PIE_TESTS_DATA_DIR;
    path += "/expected_test_results/TestLexer.txt";
    file.open (path.c_str ());

    std::string expected;
    line = "";
    while (std::getline (file, line))
        expected += line + '\n';
    file.close ();

    if (expected.size () != resultTokens.size ())
    {
        std::cout << "\n\nERROR: Result tokens dont match expected! Expected: \n\n" << expected;
        return -1;
    }
    return 0;
}
