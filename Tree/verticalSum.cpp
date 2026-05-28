#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure of binary tree node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    // DFS traversal to calculate vertical sums
    void solve(Node *root, int hd, map<int, int> &mp)
    {
        if (root == nullptr)
            return;

        // Add current node value to its vertical line
        mp[hd] += root->data;

        // Traverse left and right subtrees
        solve(root->left, hd - 1, mp);
        solve(root->right, hd + 1, mp);
    }

    vector<int> verticalSum(Node *root)
    {
        map<int, int> mp;
        vector<int> ans;

        solve(root, 0, mp);

        // Store sums from leftmost to rightmost
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{

    /*
            1
          /   \
         2     3
        / \     \
       4   5     7
            \
             6

    Vertical Sums:
    HD -2 -> 4
    HD -1 -> 2
    HD  0 -> 1 + 5 + 6 = 12
    HD +1 -> 3
    HD +2 -> 7
    */

    // Creating the tree
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->right = new Node(6);

    root->right->right = new Node(7);

    // Solution object
    Solution obj;

    // Get vertical sums
    vector<int> result = obj.verticalSum(root);

    // Print result
    cout << "Vertical Sums: ";

    for (int sum : result)
    {
        cout << sum << " ";
    }

    cout << endl;

    return 0;
}