#ifndef _AOCUTILS_H
#define _AOCUTILS_H

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

#endif