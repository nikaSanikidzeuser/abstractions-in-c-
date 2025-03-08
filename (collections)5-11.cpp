#include <iostream>
#include <vector>

using namespace std;

void reshape(vector<vector<int>> &grid, int nRows, int nCols);

int main()
{
    int nRows, nCols;
    cout << "Enter rows: ";
    cin >> nRows;

    cout << "Enter columns: ";
    cin >> nCols;

    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {8, 9, 10, 11}}; // as an example

    reshape(grid, nRows, nCols);

    return 0;
}

void reshape(vector<vector<int>> &grid, int nRows, int nCols)
{
    // Create a new reshape grid with the desired dimensions, filled with 0's
    vector<vector<int>> reshape(nRows, vector<int>(nCols, 0));

    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // Flatten the original grid into a 1D array and copy values to reshape grid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (count < nRows * nCols)
            {
                int newRow = count / nCols; // Determine the row in the new grid
                int newCol = count % nCols; // Determine the column in the new grid
                reshape[newRow][newCol] = grid[i][j];
                count++;
                
            }
        }
    }

    // Output the reshaped grid
    for (const auto &row : reshape)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}
