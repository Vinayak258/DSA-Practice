#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(vector<int> &arr, int start, int end)
    {

        // Distance array to store minimum steps
        vector<int> dist(1000, INT_MAX);

        // Queue for BFS -> {current_value, steps}
        queue<pair<int, int>> q;

        q.push({start, 0});
        dist[start] = 0;

        while (!q.empty())
        {

            auto front = q.front();
            q.pop();

            int node = front.first;
            int steps = front.second;

            // If target reached
            if (node == end)
                return steps;

            // Try multiplying with every number in arr
            for (int x : arr)
            {

                int newNode = (node * x) % 1000;

                // Visit only if better path found
                if (steps + 1 < dist[newNode])
                {

                    dist[newNode] = steps + 1;
                    q.push({newNode, steps + 1});
                }
            }
        }

        // If end cannot be reached
        return -1;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    cout << obj.minSteps(arr, start, end);

    return 0;
}