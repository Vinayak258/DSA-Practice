#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextSmaller(n, n);
        stack<int> st;

        // Find next smaller element for each index
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
                nextSmaller[i] = st.top();

            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += nextSmaller[i] - i;
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << "Number of valid subarrays: " << obj.countSubarrays(arr) << endl;

    return 0;
}