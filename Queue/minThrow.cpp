#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minThrows(int n, vector<int> &lad, vector<int> &sn)
    {
        int N = n * n;

        // jump[i] stores the destination of a snake/ladder
        // -1 means there is no snake or ladder
        vector<int> jump(N + 1, -1);

        // Store ladders
        for (int i = 0; i < lad.size(); i += 2)
        {
            jump[lad[i]] = lad[i + 1];
        }

        // Store snakes
        for (int i = 0; i < sn.size(); i += 2)
        {
            jump[sn[i]] = sn[i + 1];
        }

        // visited[i] tells whether cell i has already been visited
        vector<bool> visited(N + 1, false);

        // BFS queue:
        // {cell, number of dice throws}
        queue<pair<int, int>> q;

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();

            int cell = current.first;
            int throws = current.second;

            // Destination reached
            if (cell == N)
            {
                return throws;
            }

            // Try dice values 1 to 6
            for (int dice = 1; dice <= 6; dice++)
            {

                int next = cell + dice;

                // Cannot go beyond the last cell
                if (next > N)
                {
                    break;
                }

                // Take snake or ladder immediately
                if (jump[next] != -1)
                {
                    next = jump[next];
                }

                // Visit only once
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push({next, throws + 1});
                }
            }
        }

        // Destination cannot be reached
        return -1;
    }
};

int main()
{

    // Example 1
    int n = 6;

    vector<int> lad = {
        3, 22,
        5, 8,
        11, 35,
        20, 32};

    vector<int> sn = {
        17, 4,
        19, 7,
        34, 1,
        21, 9};

    Solution obj;

    int answer = obj.minThrows(n, lad, sn);

    cout << "Minimum dice throws = " << answer << endl;

    return 0;
}