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

// Checking input for errors or size that can cause overflow.
    if (row % 2 == 0 || row < 0 || (float)row != (float)(int)row || row > MAX)
    {
        throw invalid_argument("Col Size Must be positive odd integer." + to_string(row));
        return "";
    }

    if (col % 2 == 0 || col < 0 || (float)col != (float)(int)col || col > MAX)
    {
        throw invalid_argument("Col Size Must be positive odd integer." + to_string(col));
    }
// Checking valid ascii symbols
    if (a < ASCI_START || a > ASCI_END)
    {
        throw invalid_argument("First Symbol is not a valid ascii symbol see ascii code 33-126. \nSymbol is : " + to_string(a));
    }

    if (b < ASCI_START || b > ASCI_END)
    {
        throw invalid_argument("Second Symbol is not a valid ascii symbol see ascii code 33-126. \nSymbol is : " + to_string(b));
    }

// init parameters.
    string mat;
    string temp;
    int mid = (row / 2) + 1;
    std::vector<string> temp_array;
    int i = 0;
    int sym = 0;

    /// init first row with first symbol .
    for (size_t i = 0; i < col; i++)
    {
        temp += a;
    }

    i = 0;

/*  loop going from start row to the middle of the mat, the mat rows returns themselves after the middle row.
    so we will only need to compute them once.
    
    each iteration the loop goes from the i'th place til the col_size - i and turn the symbol ,
    while every line starts from the previous line that computed in the last iteration. 
    */
    
    while (i < mid)
    {
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

        temp_array.push_back(temp);
        i++;
        sym += 1;
    }


/*  BUILDING THE STRING
    re-init i for another while loop , a loop going from the start of the string vector to its end , adding the vector to a new string.
    the loop goes til the end of the vector adding the strings than go back to the start whice help us save the time of computition*/
    
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
