#include <iostream>
#include <vector>

class Solution
{
public:
    int countServers(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);

        // Step 1: Count the number of servers in each row and column
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int communicatingServers = 0;

        // Step 2: Count servers that share a row or column with at least one other server
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    if (rowCount[i] > 1 || colCount[j] > 1)
                    {
                        communicatingServers++;
                    }
                }
            }
        }

        return communicatingServers;
    }
};

int main()
{
    Solution sol;

    // Example 1
    std::vector<std::vector<int>> grid1 = {
        {1, 0},
        {0, 1}};
    std::cout << "Example 1 Output: " << sol.countServers(grid1) << " (Expected: 0)" << std::endl;

    // Example 2
    std::vector<std::vector<int>> grid2 = {
        {1, 0},
        {1, 1}};
    std::cout << "Example 2 Output: " << sol.countServers(grid2) << " (Expected: 3)" << std::endl;

    // Example 3
    std::vector<std::vector<int>> grid3 = {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    std::cout << "Example 3 Output: " << sol.countServers(grid3) << " (Expected: 4)" << std::endl;

    return 0;
}