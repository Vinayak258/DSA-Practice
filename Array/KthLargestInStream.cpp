#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthLargest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++)
        {
            minHeap.push(arr[i]);

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }

            if (minHeap.size() < k)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(minHeap.top());
            }
        }

        return ans;
    }
};

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    vector<int> result = obj.kthLargest(arr, k);

    cout << "Kth largest elements at each step:\n";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}