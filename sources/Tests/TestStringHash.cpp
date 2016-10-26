#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <Dwarf/Utils.hpp>

std::string GenerateRandomString ()
{
    std::string generated = "";
    int length = 5 + rand () % 45;

    for (int index = 0; index < length; index++)
    {
        char generatedChar;
        do
        {
            generatedChar = rand () % 255;
        }
        while (!std::isalnum (generatedChar));
        generated += generatedChar;
    }
    return generated;
}

int main (int argsCount, char *args [])
{
    const int CYCLES_COUNT = 100000;
    std::cout << "Started...\n";
    srand (time (0));

    for (int index = 0; index < CYCLES_COUNT; index++)
    {
        std::cout << "Cycle " << index + 1 << "/" << CYCLES_COUNT << "\n:";
        std::string firstString;
        std::string secondString;

        do
        {
            firstString = GenerateRandomString ();
            secondString = GenerateRandomString ();
        }
        while (firstString == secondString);

        std::cout << "Strings: " << firstString << " and " << secondString << "\n";
        unsigned firstHash = Dwarf::StringToHash (firstString);
        unsigned secondHash = Dwarf::StringToHash (secondString);

        std::cout << "Hashes: " << firstHash << " and " << secondHash << "\n";
        if (firstHash == secondHash)
        {
            std::cout << "ERROR: Hashes of different strings are equal!";
            return -1;
        }
    }
    std::cout << "Successfully passed!\n";
    return 0;
}
