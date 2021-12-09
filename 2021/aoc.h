/*
 * This header files contains functions for the advent of code problems.
 */
#ifndef _AOC_H
#define _AOC_H

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
// change output path here⤵ (if you're printing answer out to another file)
#define OUTPUTPATH "./output"
#define DAY01_ARRLEN 2000
#define DAY01_STRLEN 8
#define DAY02_STRLEN DAY01_STRLEN
#define DAY03_ARRLEN 12
#define DAY03_STRLEN DAY03_ARRLEN + 2
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

// start writing your f[                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                YUI]\unctions for each advent of code day here
void day1_1(std::ifstream &file)
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
    std::cout << count;
}

void day1_2(std::ifstream &file)
{
    std::vector<int> arr;
    int index = 0;
    int count = 0;
    int num;

    while (file >> num) 
        arr.push_back(num);

    for (int i = 0; i < DAY01_ARRLEN - 3; i++)
        if (arr[i + 3] > arr[i])
            count++;
    
    std::cout << count;
}

void day2_1(std::ifstream &file)
{
    int horizontal = 0;
    int depth = 0;
    
    std::string line;
    int val;
    while (file >> line >> val)
    {
        if (line.compare("forward") == 0)
            horizontal += val;
        else if (line.compare("down") == 0)
            depth += val;
        else
            depth -= val;
    }

    std::cout << horizontal * depth;
}

void day2_2(std::ifstream &file)
{
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    std::string line;
    int val;
    while (file >> line >> val)
    {
        if (line.compare("foward") == 0)
        {
            horizontal += val;
            depth += val * aim;
        }

        else if (line.compare("down") == 0)
            aim += val;
        else
            aim -= val;
    }

    std::cout << horizontal * depth;
}


void day3_1(FILE *file)
{
    int arr[DAY03_ARRLEN]; //keeps track of number of 1s in each column
    // set them all to 0, because they're filled with garbage values 
    for (int i = 0; i < DAY03_ARRLEN; i++)
        arr[i] = 0;
    int index = 0;
    while (!feof(file))
    {
        char line[DAY03_STRLEN];
        fgets(line, DAY03_STRLEN, file);

        for (int i = 0; i < DAY03_ARRLEN; i++)
            arr[i] += line[i] == '1' ? 1 : 0;
        index++;
    }

    int half = index / 2;
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
    
    std::cout << gamma * epsilon;
}
#endif