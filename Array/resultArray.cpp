#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1, arr2;

        // First operation
        arr1.push_back(nums[0]);

        // Second operation
        arr2.push_back(nums[1]);

        // Remaining elements
        for (int i = 2; i < nums.size(); i++)
        {
            if (arr1.back() > arr2.back())
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }

        // Combine arr1 and arr2
        vector<int> result = arr1;

        for (int x : arr2)
        {
            result.push_back(x);
        }

        return result;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    vector<int> result = obj.resultArray(nums);

    cout << "Result: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}