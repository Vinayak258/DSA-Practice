#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1,
                       vector<vector<int>> &img2)
    {

        int n = img1.size();

        // Store coordinates of all 1s
        vector<pair<int, int>> a, b;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        // displacement -> frequency
        map<pair<int, int>, int> mp;

        int ans = 0;

        // Try matching every 1 of img1 with every 1 of img2
        for (auto p : a)
        {
            for (auto q : b)
            {

                int dx = q.first - p.first;
                int dy = q.second - p.second;

                mp[{dx, dy}]++;

                ans = max(ans, mp[{dx, dy}]);
            }
        }

        return ans;
    }
};

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> img1(n, vector<int>(n));
    vector<vector<int>> img2(n, vector<int>(n));

    // Input img1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> img1[i][j];
        }
    }

    // Input img2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> img2[i][j];
        }
    }

    Solution obj;

    cout << obj.largestOverlap(img1, img2) << endl;

    return 0;
}