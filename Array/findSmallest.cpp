#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallest(vector<int> &arr)
    {
        // Sort the array
        sort(arr.begin(), arr.end());

        long long res = 1;

        for (int x : arr)
        {
            // If current element is greater than res,
            // then res cannot be formed
            if (x > res)
                break;

            // Update the range of sums
            res += x;
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {3, 1, 2};

    cout << obj.findSmallest(arr) << endl;

    return 0;
}