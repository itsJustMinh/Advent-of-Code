/**
 * @file aoc.h
 * @author Minh Nguyen (itsminhnguyen@outlook.com)
 * @brief This file contains all the functions for each Advent of Code day.
 * @version 0.1
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _AOC_H
#define _AOC_H

#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "aocutils.h"

// change output path here⤵ (if you're printing answer out to another file)
#define OUTPUTPATH "./output"
#define DAY03_ARRLEN 12
/*
 * ✨function naming conventions:✨
 *      day{day number}_{part number}
 *      ex: if doing day 1 part 2: day1_2
 * 
 * ⭐keep in note ⭐
 *      ALL FUNCTIONS SHOULD HAVE A RETURN TYPE OF VOID,
 *      AND FUNCTIONS SHOULD PRINT OUT ANSWER FOR DAY
 *      (either to terminal or to an outfile file)
 */

// start writing your functions for each advent of code day here
using namespace std;

/*
 * DAY 1 ➡ https://adventofcode.com/2021/day/1
 */
void day1_1(ifstream &file)
{
    int prevnum = -1;
    int count = 0;
    int num;
    while (file >> num)
    {
        if (num > prevnum && prevnum != -1)
            count++;
        prevnum = num;
    }
    cout << count;
}

void day1_2(ifstream &file)
{
    vector<int> arr;
    int count = 0;
    
    int num;
    while (file >> num) 
        arr.push_back(num);

    for (int i = 0; i < arr.size() - 3; i++)
        if (arr[i + 3] > arr[i])
            count++;
    
    cout << count;
}

/*
 * DAY 2 ➡ https://adventofcode.com/2021/day/2
 */
void day2_1(ifstream &file)
{
    int horizontal = 0;
    int depth = 0;
    
    string direction;
    int val;
    while (file >> direction >> val)
    {
        if (direction.compare("forward") == 0)
            horizontal += val;
        else if (direction.compare("down") == 0)
            depth += val;
        else
            depth -= val;
    }

    cout << horizontal * depth;
}

void day2_2(ifstream &file)
{
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    string direction;
    int val;
    while (file >> direction >> val)
    {
        if (direction.compare("foward") == 0)
        {
            horizontal += val;
            depth += val * aim;
        }

        else if (direction.compare("down") == 0)
            aim += val;
        else
            aim -= val;
    }

    cout << horizontal * depth;
}

/*
 * DAY 3 ➡ https://adventofcode.com/2021/day/3
 */
void day3_1(ifstream &file)
{
    // declare an initialize an integer array of DAY03_ARRLEN 0s.
    int arr[DAY03_ARRLEN]; // keeps track of number of 1s in each column of day3.txt
    for (int i = 0; i < DAY03_ARRLEN; i++)
        arr[i] = 0;

    int numlines = 0;
    string line;
    while (file >> line)
    {
        for (int i = 0; i < DAY03_ARRLEN; i++)
            arr[i] += line[i] == '1' ? 1 : 0;
        numlines++;
    }

    int half = numlines / 2;
    int gamma = 0;
    int max = -1;
    for (int i = 0; i < DAY03_ARRLEN; i++)
    {
        if (arr[i] > half)
        {
            gamma += 1 << (DAY03_ARRLEN - 1 - i);
            if (max == -1)
                max = i;
        }
    }
    int epsilon = gamma; // get the unsigned binary complement of gamma rate to get epsilon rate
    for (int i = 0; i < DAY03_ARRLEN - max; i++)
        epsilon ^= 1 << i;
    
    cout << gamma * epsilon;
}

void day3_2(ifstream &file)
{
    vector<string> oxygen, carbon;
    string line;
    while (file >> line)
    {
        if (line[0] == '1')
            oxygen.push_back(line);
        else
            carbon.push_back(line);
    }
    // looking at second bit b/c we already looked at the first bit when reading in file
    int index = 1;
    int olen = oxygen.size();
    int clen = carbon.size();
    int numbits = line.size();
    while (oxygen.size() > 1 && index < olen)
    {
        // find the least common bit at column `index`
        int c = day3count1s(carbon, index);
        int half = carbon.size() << 1;
        int mcb = 0;
        if (c >= half)
            mcb = 1;
        else
            mcb = 0;
        cerr << "oxygen most common bit: " << mcb << endl;
        // delete numbers if they don't have most common bit at position `index`
        for (int i = 0; i < oxygen.size(); i++)
            if (oxygen[i][index] != ('0' + mcb))
                oxygen.erase(oxygen.begin() + i);
        index++;
    }

    index = 1;
    while (carbon.size() > 1 && index < clen)
    {
        // find the most common bit at column `index`
        int c = day3count1s(carbon, index);
        int half = carbon.size() << 1;
        int lcb;
        if (c < half)
            lcb = 1;
        else
            lcb = 0;
        cerr << "carbon least common bit: " << lcb << endl;
        // delete numbers if they don't contain least common bit at position `index`
        for (int i = 0; i < carbon.size(); i++)
            if (carbon[i][index] != ('0' + lcb))
                carbon.erase(carbon.begin() + i);
        index++;
    }
    cerr << "oxygen: " << oxygen[0] << "_2\t" << btoi(oxygen[0]) << endl;
    cerr << "carbon: " << carbon[0] << "_2\t" << btoi(carbon[0]) << endl;
    cout << btoi(oxygen[0]) * btoi(carbon[0]) << endl;
}


#endif