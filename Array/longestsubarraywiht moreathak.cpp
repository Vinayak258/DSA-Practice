#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Prefix sum array
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (arr[i - 1] > k)
                pref[i] = pref[i - 1] + 1;
            else
                pref[i] = pref[i - 1] - 1;
        }

        // Monotonic decreasing stack
        stack<int> st;
        for (int i = 0; i <= n; i++)
        {
            if (st.empty() || pref[i] < pref[st.top()])
            {
                st.push(i);
            }
        }

        int ans = 0;
        for (int j = n; j >= 0; j--)
        {
            while (!st.empty() && pref[j] > pref[st.top()])
            {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    int result = obj.longestSubarray(arr, k);

    cout << "Longest subarray length = " << result << endl;

    return 0;
}