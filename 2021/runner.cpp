#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "aoc.h"

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
        cout << "What file do you want to read from?" << endl << ">> ";
        // i wonder if there's a simpler way to do this
        string line;
        cin >> line;
        fName += line;
    }

    ifstream inFile;
    inFile.open(fName);

    cout << "Attempting to open file at location: " << fName << endl;
    if (inFile.is_open())
        day1_2(inFile);
    else
        cout << "Unable to open the file." << endl;
}