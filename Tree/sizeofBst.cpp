#include <bits/stdc++.h>
using namespace std;

// Definition for Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int getSize(Node *root)
    {
        // Base case
        if (root == NULL)
            return 0;

        // Count current node + left subtree + right subtree
        return 1 + getSize(root->left) + getSize(root->right);
    }
};

int main()
{
    /*
        Example Tree:
               1
              / \
             2   3
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution obj;

    cout << "Size of Binary Tree: " << obj.getSize(root) << endl;

    return 0;
}