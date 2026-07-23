#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();

        // If there are fewer than 3 elements
        if (n < 3)
            return n;

        // Find the smallest power of 2 greater than n
        int ans = 1;
        while (ans <= n)
        {
            ans <<= 1;
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    cout << "Number of unique XOR triplets: "
         << obj.uniqueXorTriplets(nums) << endl;

    return 0;
}