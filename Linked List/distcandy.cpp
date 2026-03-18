#include <bits/stdc++.h>
using namespace std;

/* Tree Node Definition */
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    int moves;

    // Postorder DFS function
    int dfs(Node *root)
    {
        if (!root)
            return 0;

        int left_excess = dfs(root->left);
        int right_excess = dfs(root->right);

        // Count moves required to balance left & right subtrees
        moves += abs(left_excess) + abs(right_excess);

        // Return excess candies from current node
        return root->data + left_excess + right_excess - 1;
    }

    int distCandy(Node *root)
    {
        moves = 0;
        dfs(root);
        return moves;
    }
};

/* -------- Optional Driver Code for Testing -------- */

Node *buildSampleTree()
{
    // Example: [5, 0, 0, N, N, 0, 0]
    Node *root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);
    return root;
}

int main()
{
    Node *root = buildSampleTree();

    Solution obj;
    cout << obj.distCandy(root) << endl; // Output should be 6

    return 0;
}