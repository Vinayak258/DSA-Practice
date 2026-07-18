#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int findGCD(vector<int> &nums)
    {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        return gcd(mn, mx);
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    cout << "GCD of smallest and largest element = "
         << obj.findGCD(nums) << endl;

    return 0;
}