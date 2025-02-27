#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows, cols;

    cout << "rows: ";
    cin >> rows;
    cout << "columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    vector<int> values;
    cout << "Enter " << rows * cols << " values to fill the grid: ";
    for (int i = 0; i < rows * cols; ++i)
    {
        int value;
        cin >> value;
        values.push_back(value);
    }

    fillGrid(matrix, values);

    cout << "The filled grid is:\n";
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
void fillGrid(vector<vector<int>> &grid, const vector<int> &values)
{
    int index = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            grid[i][j] = values[index++];
        }
    }
}
