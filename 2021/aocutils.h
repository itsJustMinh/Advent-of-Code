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

#endif