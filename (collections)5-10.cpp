#include <iostream>
#include <vector>
using namespace std;

void fixCounts(vector<vector<bool>> &mines, vector<vector<int>> &counts);

int main()
{
    vector<vector<bool>> mineLocations = {
        {1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};

    vector<vector<int>> mineCounts(mineLocations.size(), vector<int>(mineLocations[0].size(), 0));
    
    fixCounts(mineLocations, mineCounts);

    // Optionally print the mine counts to see the results
    for (size_t i = 0; i < mineCounts.size(); i++) {
        for (size_t j = 0; j < mineCounts[i].size(); j++) {
            cout << mineCounts[i][j] << " ";
        }
        cout << endl;
    }
}

void fixCounts(vector<vector<bool>> &mines, vector<vector<int>> &counts)
{
    for (size_t i = 0; i < mines.size(); i++) {
        for (size_t j = 0; j < mines[i].size(); j++) {
            int count = 0;

            // Check the current cell itself
            if (mines[i][j] == 1) {
                count++;
            }

            // Check left
            if (j > 0 && mines[i][j - 1] == 1) {
                count++;
            }

            // Check right
            if (j < mines[i].size() - 1 && mines[i][j + 1] == 1) {
                count++;
            }

            // Check top
            if (i > 0 && mines[i - 1][j] == 1) {
                count++;
            }

            // Check top-left
            if (i > 0 && j > 0 && mines[i - 1][j - 1] == 1) {
                count++;
            }

            // Check top-right
            if (i > 0 && j < mines[i].size() - 1 && mines[i - 1][j + 1] == 1) {
                count++;
            }

            // Check bottom
            if (i < mines.size() - 1 && mines[i + 1][j] == 1) {
                count++;
            }

            // Check bottom-left
            if (i < mines.size() - 1 && j > 0 && mines[i + 1][j - 1] == 1) {
                count++;
            }

            // Check bottom-right
            if (i < mines.size() - 1 && j < mines[i].size() - 1 && mines[i + 1][j + 1] == 1) {
                count++;
            }

            // Store the count for the current cell
            counts[i][j] = count;
        }
    }
}
