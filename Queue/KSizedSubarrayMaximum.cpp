#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.maxOfSubarrays(arr, k);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
