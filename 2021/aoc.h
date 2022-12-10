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
#define OUTPUT_PATH "./output"
#define DAY03_ARRAY_LEN 12
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
void day1_1(ifstream &file);
void day1_2(ifstream &file);

/*
 * DAY 2 ➡ https://adventofcode.com/2021/day/2
 */
void day2_1(ifstream &file);
void day2_2(ifstream &file);

/*
 * DAY 3 ➡ https://adventofcode.com/2021/day/3
 */
void day3_1(ifstream &file);
void day3_2(ifstream &file);


#endif