#include "mat.hpp"
using namespace ariel;

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

const int ASCI_START = 33;
const int ASCI_END = 126;
const int MAX = 100000;
string ariel::mat(int col, int row, char a, char b)
{

    if (row % 2 == 0 || row < 0 || (float)row != (float)(int)row || row > MAX)
    {
        throw invalid_argument("Col Size Must be positive odd integer." + to_string(row));
        return "";
    }

    if (col % 2 == 0 || col < 0 || (float)col != (float)(int)col || col > MAX)
    {
        throw invalid_argument("Col Size Must be positive odd integer." + to_string(col));
    }

    if (a < ASCI_START || a > ASCI_END)
    {
        throw invalid_argument("First Symbol is not a valid ascii symbol see ascii code 33-126. \nSymbol is : " + to_string(a));
    }

    if (b < ASCI_START || b > ASCI_END)
    {
        throw invalid_argument("Second Symbol is not a valid ascii symbol see ascii code 33-126. \nSymbol is : " + to_string(b));
    }
    string mat;
    string temp;
    int mid = (row / 2) + 1;
    std::vector<string> temp_array;
    int i = 0;
    int sym = 0;

    /// init row
    for (size_t i = 0; i < col; i++)
    {
        temp += a;
    }

    i = 0;

    while (i < mid)
    {
        // cout << i << "temp = " << temp << '\n'
        //      << endl;
        for (int j = i; j < col - i; j++)
        {
            if (sym % 2 == 0)
            {
                temp.at(j) = a;
            }
            else
            {
                temp.at(j) = b;
            }
        }
        // cout << i << "temp after = " << temp << '\n'
        //      << endl;
        temp_array.push_back(temp);
        i++;
        sym += 1;
    }

    i = 0;
    int next = 1;
    while (true)
    {
        if (i == -1)
        {
            break;
        }

        mat += temp_array[i];
        mat += '\n';
        if (i == mid - 1)
        {
            next = -1;
        }
        i += next;
    }

    return mat;
}

// int main(int argc, char const *argv[])
// {

//     string mat_a = mat(17, 15, '@', '#');

//     for (size_t i = 0; i < mat_a.size(); i++)
//     {
//         if (mat_a[i] == '@')
//         {
//             string colorized_sym = "\x1B[32m";
//             colorized_sym+=mat_a[i];
//             cout << colorized_sym;
//         }

//         else if (mat_a[i] == '#')
//         {
//             string colorized_sym = "\x1B[31m";
//             colorized_sym+=mat_a[i];
//             cout << colorized_sym;        }

//         else
//             cout << mat_a[i];
//     }

//     cout << endl;
//     return 0;
// }
