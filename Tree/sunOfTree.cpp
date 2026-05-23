#include <bits/stdc++.h>
using namespace std;

/* Structure for Tree Node */
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    // Function to convert tree into Sum Tree
    int solve(Node *root)
    {
        if (root == nullptr)
            return 0;

        // Recursively get sum of left and right subtrees
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // Store old value
        int oldValue = root->data;

        // Update current node
        root->data = leftSum + rightSum;

        // Return total sum of original subtree
        return oldValue + root->data;
    }

    void toSumTree(Node *root)
    {
        solve(root);
    }
};

// Function for inorder traversal
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    /*
            10
           /  \
         -2    6
         / \   / \
        8 -4 7  5
    */

    Node *root = new Node(10);

    root->left = new Node(-2);
    root->right = new Node(6);

    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution obj;

    cout << "Inorder before conversion:\n";
    inorder(root);

    obj.toSumTree(root);

    cout << "\n\nInorder after conversion to Sum Tree:\n";
    inorder(root);

    return 0;
}