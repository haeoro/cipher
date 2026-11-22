/*------------------------------------------------------------------------------
*   ``~CLI based encryption tool written by haeoro~``
*
*   getRandNumber() simply generates a random number when called.
------------------------------------------------------------------------------*/

#include <iostream>
#include <ctime>
#include <string>
#include "random.h"
#include <windows.h>
#include <vector>

int usage()
{
    std::cout << "cipher -e MESSAGE\n";
    return 1;
}

int main(int argc, char *argv[])
{
    char etac[] = "-e";
    if (argc < 2)
    {
        usage();
        return 1;
    }

    // call encrypt if strcmp evals to false
    std::vector<int> decryptkey = {};
    std::vector<char> specialMsg = {};
    int sIndex = 0;
    int argLength = strlen(argv[2]);
    while ( sIndex != argLength )
    {
        // while this is going do encrypting... then display decryption key
        Sleep(1000);
        std::cout << "working...\n";
        int randNum = randnum();
        auto pos = decryptkey.begin();
        pos = decryptkey.insert(pos, randNum);
        specialMsg.push_back(((char)(argv[2][sIndex] + randNum)));
        sIndex++;
        pos++;
    }

    std::cout << "complete!\n\n";
    std::cout << "original message: " << argv[2] << '\n';
    std::cout << "encrypted message: ";
    for (int i = 0; i != specialMsg.size(); i++)
    {
        std::cout << specialMsg[i];
    }
    std::cout << "\ndecryption key: ";
    for (int i = decryptkey.size()-1; i != -1; i--)
    {
        //std::cout << key.size();
        std::cout << decryptkey[i];
    }
    std::cout << '\n';
}

/*
notes!
    ~ main method of random num generation for the encryption program is all
    within the getRandNumber function.
    ~ if it returns 1 as rval i have to like find a way to make it try again or add some value
    to it.

~ to-do
    ~ clean up code/ seggregate code into functions and/or .h files.
    make sure the UI looks clean and the messages look nice. we want
    a smooth user experience.
    ~ write a decrypter algorithm that takes a decryptkey.
    ~ document functions and header files clearly and concisely.

*/
