
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        const int MOD = 1e9 + 7;

        long long even = 1, odd = 0;
        long long prefix = 0;
        long long ans = 0;

        for (int num : arr)
        {
            prefix += num;

            if (prefix % 2 == 0)
            {
                ans = (ans + odd) % MOD;
                even++;
            }
            else
            {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = obj.numOfSubarrays(arr);

    cout << "Number of subarrays with odd sum: " << result << endl;

    return 0;
}
