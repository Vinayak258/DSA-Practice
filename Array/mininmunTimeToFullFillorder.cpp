#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int time, vector<int> &ranks, int n)
    {
        int donuts = 0;

        for (int r : ranks)
        {
            int low = 1, high = n, cnt = 0;

            while (low <= high)
            {
                int mid = (low + high) / 2;
                long long requiredTime = 1LL * r * mid * (mid + 1) / 2;

                if (requiredTime <= time)
                {
                    cnt = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            donuts += cnt;
            if (donuts >= n)
                return true;
        }
        return false;
    }

    int minTime(vector<int> &ranks, int n)
    {
        int minRank = *min_element(ranks.begin(), ranks.end());
        int low = 0;
        int high = minRank * n * (n + 1) / 2;
        int ans = high;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isPossible(mid, ranks, n))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ranks(m);
    for (int i = 0; i < m; i++)
    {
        cin >> ranks[i];
    }

    Solution obj;
    cout << obj.minTime(ranks, n) << endl;

    return 0;
}
