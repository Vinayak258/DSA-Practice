#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> pos(n + 1);

        // Store position of every value
        for (int i = 0; i < n; i++)
        {
            pos[arr[i]] = i;
        }

        int longest = 1;
        int current = 1;

        // Find longest consecutive values
        // whose positions are increasing
        for (int x = 1; x < n; x++)
        {
            if (pos[x] < pos[x + 1])
            {
                current++;
            }
            else
            {
                current = 1;
            }

            longest = max(longest, current);
        }

        return n - longest;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.minMoves(arr) << endl;

    return 0;
}