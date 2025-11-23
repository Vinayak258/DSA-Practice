#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        auto isPossible = [&](int d)
        {
            long long sum = 0;
            for (int x : nums)
                sum += (x + d - 1) / d; // ceil(x / d)
            return sum <= threshold;
        };

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isPossible(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main()
{
    // Example input:
    // nums = [1,2,5,9], threshold = 6

    int n, threshold;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter threshold: ";
    cin >> threshold;

    Solution sol;
    int result = sol.smallestDivisor(nums, threshold);

    cout << "Smallest Divisor = " << result << endl;

    return 0;
}
