#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int freq, order;
        Node *left, *right;

        Node(int f, int o)
        {
            freq = f;
            order = o;
            left = right = nullptr;
        }
    };

    struct cmp
    {
        bool operator()(Node *a, Node *b)
        {
            if (a->freq == b->freq)
                return a->order > b->order; // earlier inserted first
            return a->freq > b->freq;
        }
    };

    void preorder(Node *root, string code, vector<string> &ans)
    {
        if (!root)
            return;

        // leaf node
        if (!root->left && !root->right)
        {
            ans.push_back(code);
            return;
        }

        preorder(root->left, code + "0", ans);
        preorder(root->right, code + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        int order = 0;

        // Insert all frequencies
        for (int i = 0; i < f.size(); i++)
        {
            pq.push(new Node(f[i], order++));
        }

        // Build Huffman Tree
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *parent = new Node(left->freq + right->freq, order++);
            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }

        Node *root = pq.top();
        vector<string> ans;
        preorder(root, "", ans);

        return ans;
    }
};

int main()
{
    string s;
    int n;

    cout << "Enter string of distinct characters: ";
    cin >> s;

    n = s.size();
    vector<int> freq(n);

    cout << "Enter frequencies: ";
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }

    Solution obj;
    vector<string> ans = obj.huffmanCodes(s, freq);

    cout << "Huffman Codes:\n";
    for (string code : ans)
    {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}