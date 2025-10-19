#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSorted(vector<int> &arr, int l, int r)
    {
        for (int i = l; i < r - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    bool rotatedSorted(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                count++;
            }
        }

        return count <= 1;
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

    if (s1.rotatedSorted(arr))
    {
        cout << "Yes, Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted " << endl;
    }
    return 0;
}