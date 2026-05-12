#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> segTree;
    int n;

    // Function to calculate GCD
    long long gcdLL(long long a, long long b)
    {
        while (b)
        {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    // Function to calculate LCM
    long long lcmLL(long long a, long long b)
    {
        return (a / gcdLL(a, b)) * b;
    }

    // Build Segment Tree
    void build(int idx, int l, int r, vector<int> &arr)
    {

        if (l == r)
        {
            segTree[idx] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx + 1, l, mid, arr);
        build(2 * idx + 2, mid + 1, r, arr);

        segTree[idx] = lcmLL(segTree[2 * idx + 1],
                             segTree[2 * idx + 2]);
    }

    // Update Query
    void update(int idx, int l, int r, int pos, int val)
    {

        if (l == r)
        {
            segTree[idx] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx + 1, l, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, r, pos, val);

        segTree[idx] = lcmLL(segTree[2 * idx + 1],
                             segTree[2 * idx + 2]);
    }

    // Range LCM Query
    long long query(int idx, int l, int r, int ql, int qr)
    {

        // No overlap
        if (r < ql || l > qr)
            return 1;

        // Complete overlap
        if (ql <= l && r <= qr)
            return segTree[idx];

        int mid = (l + r) / 2;

        long long left = query(2 * idx + 1, l, mid, ql, qr);
        long long right = query(2 * idx + 2, mid + 1, r, ql, qr);

        return lcmLL(left, right);
    }

    vector<long long> RangeLCMQuery(vector<int> &arr,
                                    vector<vector<int>> &queries)
    {

        n = arr.size();

        segTree.resize(4 * n);

        build(0, 0, n - 1, arr);

        vector<long long> ans;

        for (auto &q : queries)
        {

            // Update Query
            if (q[0] == 1)
            {

                int index = q[1];
                int value = q[2];

                update(0, 0, n - 1, index, value);
            }

            // Range Query
            else if (q[0] == 2)
            {

                int L = q[1];
                int R = q[2];

                ans.push_back(query(0, 0, n - 1, L, R));
            }
        }

        return ans;
    }
};

int main()
{

    vector<int> arr = {2, 3, 4, 6, 8, 16};

    vector<vector<int>> queries = {
        {2, 0, 2},
        {1, 3, 8},
        {2, 2, 5}};

    Solution obj;

    vector<long long> result =
        obj.RangeLCMQuery(arr, queries);

    cout << "Output: ";

    for (long long x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}