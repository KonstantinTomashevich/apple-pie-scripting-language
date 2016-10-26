#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Defines.hpp"
#include <Dwarf/Lexer/Lexer.hpp>
#include <Dwarf/Utils.hpp>

std::string TokenDataToString (Dwarf::TokenData tokenData)
{
    if (tokenData.type_ == Dwarf::TOKEN_END_OF_LINE)
        return "END_OF_LINE";

    else if (tokenData.type_ == Dwarf::TOKEN_IDENTIFIER)
        return "IDENTIFIER '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == Dwarf::TOKEN_NUMERIC_LITERAL)
        return "NUMBER '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == Dwarf::TOKEN_STRING_LITERAL)
        return "STRING '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == Dwarf::TOKEN_NOT_ALNUM_SYMBOLS)
        return "NOT_ALNUM_SYMBOLS '" + tokenData.additionalDataStr_ + "'";

    else if (tokenData.type_ == Dwarf::TOKEN_LOCAL)
        return "LOCAL";

    else if (tokenData.type_ == Dwarf::TOKEN_GLOBAL)
        return "GLOBAL";

    else if (tokenData.type_ == Dwarf::TOKEN_MEMBER)
        return "MEMBER";

    else if (tokenData.type_ == Dwarf::TOKEN_DEFINE)
        return "DEFINE";

    else if (tokenData.type_ == Dwarf::TOKEN_CLASS)
        return "CLASS";

    else if (tokenData.type_ == Dwarf::TOKEN_INHERITS)
        return "INHERITS";

    else if (tokenData.type_ == Dwarf::TOKEN_IF)
        return "IF";

    else if (tokenData.type_ == Dwarf::TOKEN_ELSE)
        return "ELSE";

    else if (tokenData.type_ == Dwarf::TOKEN_FOR)
        return "FOR";

    else if (tokenData.type_ == Dwarf::TOKEN_IN_RANGE)
        return "IN_RANGE";

    else if (tokenData.type_ == Dwarf::TOKEN_WITH_STEP)
        return "WITH_STEP";

    else if (tokenData.type_ == Dwarf::TOKEN_WHILE)
        return "WHILE";

    else if (tokenData.type_ == Dwarf::TOKEN_DO_WHILE)
        return "DO_WHILE";

    else if (tokenData.type_ == Dwarf::TOKEN_FOREACH)
        return "FOREACH";

    else if (tokenData.type_ == Dwarf::TOKEN_IN)
        return "IN";

    else if (tokenData.type_ == Dwarf::TOKEN_RETURN)
        return "RETURN";

    else if (tokenData.type_ == Dwarf::TOKEN_COPY_OF)
        return "COPY_OF";

    else if (tokenData.type_ == Dwarf::TOKEN_REF_TO)
        return "REF_TO";

    else if (tokenData.type_ == Dwarf::TOKEN_CODE_BLOCK_START)
        return "CODE_BLOCK_START";

    else if (tokenData.type_ == Dwarf::TOKEN_CODE_BLOCK_END)
        return "CODE_BLOCK_END";

    else if (tokenData.type_ == Dwarf::TOKEN_OBJECT_ACCESS)
        return "OBJECT_ACESS";

    else if (tokenData.type_ == Dwarf::TOKEN_OPEN_CIRCLE_BRACKET)
        return "OPEN_CIRCLE_BRACKETS";

    else if (tokenData.type_ == Dwarf::TOKEN_CLOSE_CIRCLE_BRACKET)
        return "CLOSE_CIRCLE_BRACKETS";

    else if (tokenData.type_ == Dwarf::TOKEN_OPEN_QUAD_BRACKET)
        return "OPEN_QUAD_BRACKETS";

    else if (tokenData.type_ == Dwarf::TOKEN_CLOSE_QUAD_BRACKET)
        return "CLOSE_QUAD_BRACKETS";

    else if (tokenData.type_ == Dwarf::TOKEN_END_OF_INPUT)
         return "END_OF_INPUT";

    else
        return "UNKNOWN TOKEN";
}

int main (int argsCount, char *args [])
{
    std::cout << "Reading test code...";
    std::ifstream file;
    std::string path;
    path += DWARF_TESTS_DATA_DIR;
    path += "/for_testing/ForLexerTest.dwarf";
    file.open (path.c_str ());

    // TODO: About test code. I think using Main (arguments) function is better.

    std::string code;
    std::string line;
    while (std::getline (file, line))
        code += line + '\n';
    file.close ();
    std::cout << "done.\n\n" << code;

    Dwarf::Lexer lexer;
    std::vector <Dwarf::TokenData> tokens = lexer.Process (code);
    std::cout << "\n\nTokens count -- " << tokens.size () << ". Tokens:\n\n";

    std::string resultTokens = "";
    for (int index = 0; index < tokens.size (); index++)
    {
        resultTokens += Dwarf::IntToString (index);
        resultTokens += ": Line ";
        resultTokens += Dwarf::IntToString (tokens.at (index).lineIndex_);
        resultTokens += " -- ";
        resultTokens += TokenDataToString (tokens.at (index));
        resultTokens += "\n";
    }
    std::cout << resultTokens;

    path = DWARF_TESTS_DATA_DIR;
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
