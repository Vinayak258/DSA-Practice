#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countIncreasing(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        int len = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                len++;
                ans += (len - 1);
            }
            else
            {
                len = 1;
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n; // size of array

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.countIncreasing(arr) << endl;

    return 0;
}