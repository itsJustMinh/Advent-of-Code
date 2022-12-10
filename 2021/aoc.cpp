#include "./aoc.h"

void day1_1(ifstream &file)
{
    int prevNum = -1;
    int count = 0;
    int num;
    while (file >> num)
    {
        if (num > prevNum && prevNum != -1)
            count++;
        prevNum = num;
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
        if (direction.compare("forward") == 0)
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

void day3_1(ifstream &file)
{
    // declare an initialize an integer array of DAY03_ARRAY_LEN 0s.
    int arr[DAY03_ARRAY_LEN]; // keeps track of number of 1s in each column of day3.txt
    for (int i = 0; i < DAY03_ARRAY_LEN; i++)
        arr[i] = 0;

    int numLines = 0;
    string line;
    while (file >> line)
    {
        for (int i = 0; i < DAY03_ARRAY_LEN; i++)
            arr[i] += line[i] == '1' ? 1 : 0;
        numLines++;
    }

    int half = numLines / 2;
    int gamma = 0;
    int max = -1;
    for (int i = 0; i < DAY03_ARRAY_LEN; i++)
    {
        if (arr[i] > half)
        {
            gamma += 1 << (DAY03_ARRAY_LEN - 1 - i);
            if (max == -1)
                max = i;
        }
    }
    int epsilon = gamma; // get the unsigned binary complement of gamma rate to get epsilon rate
    for (int i = 0; i < DAY03_ARRAY_LEN - max; i++)
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
        int count = 0;
        for (int i = 0; i < oxygen.size(); i++)
            if (oxygen[i][index] == '1')
                count++;

        int half = oxygen.size() >> 1;
        int lcb = count >= half ? 0 : 1;

        // delete numbers if they have least common bit at position `index`
        for (int i = 0; i < oxygen.size(); i++)
            if (oxygen[i][index] == ('0' + lcb))
                oxygen.erase(oxygen.begin() + i);
        index++;
    }

    index = 1;
    while (carbon.size() > 1 && index < clen)
    {
        // find the most common bit at column `index`
        int count = 0;
        for (int i = 0; i < carbon.size(); i++)
            if (carbon[i][index] == '1')
                count++;
        int mcb = count > (carbon.size() >> 1) ? 1 : 0;

        // delete numbers if they have most common bit at position `index`
        for (int i = 0; i < carbon.size(); i++)
            if (carbon[i][index] == ('0' + mcb))
                carbon.erase(carbon.begin() + i);
        index++;
    }
    cerr << "oxygen: " << oxygen[0] << "_2\t" << btoi(oxygen[0]) << endl;
    cerr << "carbon: " << carbon[0] << "_2\t" << btoi(carbon[0]) << endl;
    cout << btoi(oxygen[0]) * btoi(carbon[0]) << endl;
}