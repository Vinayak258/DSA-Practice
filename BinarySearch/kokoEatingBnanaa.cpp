#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        auto canFinish = [&](int k)
        {
            long long hours = 0;
            for (int p : piles)
            {
                hours += (p + k - 1) / k;
            }

            return hours <= h;
        };

        while (left < right)
        {

            int mid = left + (right - left) / 2;

            if (canFinish(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution sol;
    int result = sol.minEatingSpeed(piles, h);

    cout << "Minimum eating speed = " << result << endl;

    return 0;
}