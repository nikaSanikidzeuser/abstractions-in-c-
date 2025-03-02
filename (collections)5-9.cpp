#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
#include <set>
using namespace std;

bool checkSudokuSolution(vector<vector<int>> &puzzle);
int main()
{
    vector<vector<int>> puzzle = {
        {3, 9, 2, 4, 6, 5, 8, 1, 7},
        {7, 4, 1, 8, 9, 3, 6, 2, 5},
        {6, 8, 5, 2, 7, 1, 4, 3, 9},
        {2, 5, 4, 1, 3, 8, 7, 9, 6},
        {8, 3, 9, 6, 2, 7, 1, 5, 4},
        {1, 7, 6, 9, 5, 4, 2, 8, 3},
        {9, 6, 7, 5, 8, 2, 3, 4, 1},
        {4, 2, 3, 7, 1, 9, 5, 6, 8},
        {5, 1, 8, 3, 4, 6, 9, 7, 2}};

    if (checkSudokuSolution(puzzle))
    {
        cout << "it is ";
    }
    else
    {
        cout << "it is not ";
    }
}
bool checkSudokuSolution(vector<vector<int>> &puzzle)
{
    // rows
    for (int i = 0; i < puzzle.size(); i++)
    {
        set<int> values;
        for (int j = 0; j < puzzle[i].size(); j++)
        {
            values.insert(puzzle[i][j]);
        }
        if (values.size() != 9)
        {
            return false;
        }
    }
    // columns
    for (int j = 0; j < puzzle.size(); j++)
    {
        set<int> values;
        for (int i = 0; i < puzzle[i].size(); i++)
        {
            values.insert(puzzle[i][j]);
        }
        if (values.size() != 9)
        {
            return false;
        }
    }
   
   // 3x3 size checks
for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            set<int> values;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    values.insert(puzzle[row + i][col + j]);
                }
            }
            if (values.size() != 9) {
                return false;
            }
        }
    }


    return true;
}
