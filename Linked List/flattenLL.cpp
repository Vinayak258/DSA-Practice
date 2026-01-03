#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Function to print flattened list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}

class Solution
{
private:
    Node *merge(Node *a, Node *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;

        Node *result;

        if (a->data < b->data)
        {
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else
        {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        result->next = NULL;
        return result;
    }

public:
    Node *flatten(Node *root)
    {
        if (!root || !root->next)
            return root;

        root->next = flatten(root->next);
        root = merge(root, root->next);

        return root;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *prev = NULL;

        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;

            int x;
            cin >> x;
            Node *temp = new Node(x);

            if (!head)
                head = temp;
            else
                prev->next = temp;

            prev = temp;

            Node *curr = temp;
            for (int j = 1; j < m; j++)
            {
                cin >> x;
                curr->bottom = new Node(x);
                curr = curr->bottom;
            }
        }

        Solution obj;
        Node *flatHead = obj.flatten(head);
        printList(flatHead);
    }
    return 0;
}
