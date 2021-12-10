#ifndef _AOCUTILS_H
#define _AOCUTILS_H

#include <vector>
#include <string>

using namespace std;

// converts a binary number (in a string form) to an integer
int btoi(string b)
{
    int res;
    int max = b.size();
    for (int i = 0; i < max; i++)
        res += (b[max - 1 - i] == '1' ? 1 : 0) * (1 << i);
    return res;
}

// gets index of a string in a string array
int indexOf(string arr[], int size, string target)
{
    for (int i = 0; i < size; i++)
        if (arr[i].compare(target) == 0)
            return i;
    return -1;
}

/**
 * @brief For aoc day 3, it returns the count of 1s found in the position of a vector string,
 *        where the vector contains strings comprised of '0' and '1' characters.
 * 
 * @param v the vector of strings containing 0 and 1
 * @param pos the position of the string to look at
 * @return int -- the number of '1's found in the position `pos` in each string in the vector
 */
int day3count1s(vector<string> v, int pos)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i][pos] == '1')
            count++;

    return count;
}

#endif