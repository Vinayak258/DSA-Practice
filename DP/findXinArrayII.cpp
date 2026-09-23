#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt[5] = {0};
    int prod = 0;
};

class SegmentTree
{
public:
    int n, k;
    vector<Node> segTree;

    SegmentTree(vector<int> &nums, int k)
    {
        this->k = k;
        n = nums.size();

        segTree.assign(4 * n, Node());

        build(0, 0, n - 1, nums);
    }

    // Build segment tree
    void build(int i, int l, int r, vector<int> &nums)
    {

        if (l == r)
        {
            leafNode(i, nums[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, nums);
        build(2 * i + 2, mid + 1, r, nums);

        segTree[i] = mergeNodes(
            segTree[2 * i + 1],
            segTree[2 * i + 2]);
    }

    // Create node for one element
    void leafNode(int i, int value)
    {

        for (int x = 0; x < k; x++)
        {
            segTree[i].cnt[x] = 0;
        }

        int rem = value % k;

        // Only one non-empty prefix
        segTree[i].cnt[rem] = 1;

        // Product of this segment
        segTree[i].prod = rem;
    }

    // Merge two adjacent nodes
    Node mergeNodes(const Node &left, const Node &right)
    {

        Node result;

        // Product of complete segment
        result.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int x = 0; x < k; x++)
        {
            result.cnt[x] = left.cnt[x];
        }

        // Prefixes which extend from left into right
        for (int x = 0; x < k; x++)
        {

            int newRem = (left.prod * x) % k;

            result.cnt[newRem] += right.cnt[x];
        }

        return result;
    }

    // Update one position
    void segTreeUpdate(
        int i,
        int l,
        int r,
        int index,
        int value)
    {

        if (l == r)
        {
            leafNode(i, value);
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
        {

            segTreeUpdate(
                2 * i + 1,
                l,
                mid,
                index,
                value);
        }
        else
        {

            segTreeUpdate(
                2 * i + 2,
                mid + 1,
                r,
                index,
                value);
        }

        // Recalculate current node
        segTree[i] = mergeNodes(
            segTree[2 * i + 1],
            segTree[2 * i + 2]);
    }

    void update(int index, int value)
    {

        segTreeUpdate(
            0,
            0,
            n - 1,
            index,
            value);
    }

    // Query range [start, end]
    Node segTreeQuery(
        int start,
        int end,
        int i,
        int l,
        int r)
    {

        // Complete overlap
        if (l >= start && r <= end)
        {
            return segTree[i];
        }

        int mid = l + (r - l) / 2;

        // Query completely in left
        if (end <= mid)
        {

            return segTreeQuery(
                start,
                end,
                2 * i + 1,
                l,
                mid);
        }

        // Query completely in right
        if (start > mid)
        {

            return segTreeQuery(
                start,
                end,
                2 * i + 2,
                mid + 1,
                r);
        }

        // Query both sides
        Node left = segTreeQuery(
            start,
            end,
            2 * i + 1,
            l,
            mid);

        Node right = segTreeQuery(
            start,
            end,
            2 * i + 2,
            mid + 1,
            r);

        return mergeNodes(left, right);
    }

    Node query(int start, int end)
    {

        return segTreeQuery(
            start,
            end,
            0,
            0,
            n - 1);
    }
};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));

    for (int i = 0; i < q; i++)
    {

        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    SegmentTree segTree(nums, k);

    vector<int> result;

    for (auto &query : queries)
    {

        int index = query[0];
        int value = query[1];
        int start = query[2];
        int x = query[3];

        // Update nums[index]
        segTree.update(index, value);

        // Query nums[start ... n-1]
        Node node = segTree.query(start, n - 1);

        // Number of valid prefixes with product % k == x
        result.push_back(node.cnt[x]);
    }

    // Print answer
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}