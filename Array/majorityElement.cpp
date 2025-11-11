#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Boyer–Moore’s Majority Vote Algorithm,
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int ele = -1;

        for (int i = 0; i < nums.size(); i++)
        {

            if (cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
            }
            else if (nums[i] == ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ele == nums[i])
            {
                cnt1++;
            }
        }
        if (cnt1 > (nums.size()) / 2)
        {
            return ele;
        }

        return -1;
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr(n, 0);
    cout << "Enter array element : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Majority Element in array is " << s1.majorityElement(arr) << endl;

    return 0;
}