#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int xor1 = 0, xor2 = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i + 1);
        }

        return xor1 ^ xor2;
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Missing number in the array is : " << s1.missingNumber(arr);

    return 0;
}