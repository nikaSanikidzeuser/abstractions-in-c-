#include <iostream>
#include <vector>

using namespace std;

bool isMagicSquare(vector<vector<int>> &grid);

int main()
{

    int rows, cols;
    int num;
    cout << "enter rows : ";
    cin >> rows;
    cout << "enter cols : ";
    cin >> cols;
    if (rows != cols)
    {
        cout << "cols and rows should be equal";
    }
    else
    {
        vector<int> values;
        cout << "enter values : ";
        for (int i = 0; i < rows * cols; i++)
        {
            cin >> num;
            values.push_back(num);
        }
        vector<vector<int>> grid(rows, vector<int>(cols));
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                grid[i][j] = values[count++];
            }
        }

        if (isMagicSquare(grid))
        {
            cout << "success: it is " << endl;
        }
        else
        {
            cout << "error: it is not " << endl;
        }
    }

    return 0;
}

bool isMagicSquare(vector<vector<int>> &grid)
{
    int sum = 0;
    for (int i = 0; i < grid[0].size(); i++)
    {
        sum += grid[0][i];
    }
    for (int i = 0; i < grid.size(); i++)
    {
        int rowSum = 0;
        for (int j = 0; j < grid[i].size(); j++)
        {
            rowSum += grid[i][j];
        }
        if (rowSum != sum)
            return false;
    }

    for (int i = 0; i < grid.size(); i++)
    {
        int columnSum = 0;
        for (int j = 0; j < grid[i].size(); j++)
        {
            columnSum += grid[j][i];
        }
        if (columnSum != sum)
            return false;
    }
    int firstDiagonalSum = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        firstDiagonalSum += grid[i][i];
    }
    if (firstDiagonalSum != sum)
        return false;
    int secondDiagonalSum = 0;
    int j = 0;
    for (int i = grid.size() - 1; i >= 0; i--)
    {
        secondDiagonalSum += grid[i][j++];
    }
    return (secondDiagonalSum == sum);
}
