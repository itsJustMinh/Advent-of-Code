#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "aoc.h"

// ./input/dayxx.txt\0 is 18 characters long
#define STRLEN 18
// change file path here⤵
#define INPUTPATH "./input/"


using namespace std;

int main(int argc, char *args[])
{
    string fName;
    fName += INPUTPATH;
    if (argc >= 2)
        fName += args[1];
    else
    {
        std::cout << "What file do you want to read from?" << endl;
        cin >> fName;
    }

    ifstream inFile;
    inFile.open(fName);

    if (inFile.is_open())
        day1_2(inFile);
    else
        cout << "Unable to open file " << fName << endl;
}