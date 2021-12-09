/**
 * @file runner.cpp
 * @author Minh Nguyen (itsminhnguyen@outlook.com)
 * @brief This file is used to run functions created in aoc.h
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <fstream>
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

    cout << "Attempting to open file at location: " << fName << ":" << endl;
    if (inFile.is_open())
    {
        try
        {
            day3_2(inFile);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << endl;
            cerr << "Something bad happened while running line 36 in ./runner.cpp" << endl;
        }
    }
    else
        cout << "Unable to open the file." << endl;
}