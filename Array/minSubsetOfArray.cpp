#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubsets(vector<int> &arr)
    {
        // Sort the array
        sort(arr.begin(), arr.end());

        // At least one subset is needed
        int count = 1;

        // Count breaks in consecutive sequence
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i - 1] + 1)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << "Minimum number of subsets: " << obj.minSubsets(arr) << endl;

    return 0;
}