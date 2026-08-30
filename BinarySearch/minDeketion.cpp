#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Make left the smaller index
        // and right the larger index
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // 1. Remove both from the front
        int front = right + 1;

        // 2. Remove both from the back
        int back = n - left;

        // 3. Remove left element from front
        //    and right element from back
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;

    int answer = obj.minimumDeletions(nums);

    cout << "Minimum deletions = " << answer << endl;

    return 0;
}