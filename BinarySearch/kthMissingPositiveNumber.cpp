#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int expected = 1;
        for (int num : arr)
        {
            if (num > expected)
            {
                int missing = num - expected;
                if (k <= missing)
                    return expected + k - 1;
                k -= missing;
            }
            expected = num + 1;
        }
        return expected + k - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << sol.findKthPositive(arr, k) << endl;
    return 0;
}
