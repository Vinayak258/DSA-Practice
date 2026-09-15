#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node Structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        if (root == nullptr)
            return 0;

        vector<int> leafLevels;

        // Queue stores {node, level}
        queue<pair<Node *, int>> q;
        q.push({root, 1});

        while (!q.empty())
        {
            Node *node = q.front().first;
            int level = q.front().second;
            q.pop();

            // Leaf node
            if (node->left == nullptr && node->right == nullptr)
            {
                leafLevels.push_back(level);
                continue;
            }

            // Left child
            if (node->left != nullptr)
            {
                q.push({node->left, level + 1});
            }

            // Right child
            if (node->right != nullptr)
            {
                q.push({node->right, level + 1});
            }
        }

        // Cheapest leaves first
        sort(leafLevels.begin(), leafLevels.end());

        int count = 0;

        for (int cost : leafLevels)
        {
            if (cost > k)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};

// Function to build tree from level-order input
// -1 represents NULL
Node *buildTree(vector<int> arr)
{
    if (arr.empty() || arr[0] == -1)
        return nullptr;

    Node *root = new Node(arr[0]);

    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size())
    {
        Node *current = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1)
        {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1)
        {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main()
{

    // Example 1
    vector<int> arr = {10, 8, 2, 3, -1, 3, 6, -1, -1, -1, 4};

    int k = 8;

    Node *root = buildTree(arr);

    Solution obj;

    cout << "Maximum number of leaf nodes = "
         << obj.getCount(root, k) << endl;

    return 0;
}