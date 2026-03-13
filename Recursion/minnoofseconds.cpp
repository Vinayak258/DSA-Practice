#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(long long T, int mountainHeight, vector<int> &workerTimes)
    {
        long long total = 0;

        for (long long t : workerTimes)
        {

            long long l = 0, r = 1000000;

            while (l <= r)
            {
                long long mid = (l + r) / 2;

                long long time = t * (mid * (mid + 1) / 2);

                if (time <= T)
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            total += r;

            if (total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {

        long long low = 0, high = 1e18;
        long long ans = high;

        while (low <= high)
        {

            long long mid = (low + high) / 2;

            if (canFinish(mid, mountainHeight, workerTimes))
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

    int mountainHeight;
    int n;

    cin >> mountainHeight;
    cin >> n;

    vector<int> workerTimes(n);

    for (int i = 0; i < n; i++)
        cin >> workerTimes[i];

    Solution obj;

    cout << obj.minNumberOfSeconds(mountainHeight, workerTimes);

    return 0;
}