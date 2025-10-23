#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter number : ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Single number in array is : " << s1.singleNumber(arr) << endl;

    return 0;
}