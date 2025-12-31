#include <bits/stdc++.h>
using namespace std;

/* Node definition */
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if (!head || !head->next)
            return true;

        // Find middle of the list
        Node *slow = head;
        Node *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node *secondHalf = reverseList(slow->next);
        Node *firstHalf = head;

        // Compare both halves
        while (secondHalf)
        {
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "true";
        return 0;
    }

    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    Solution obj;
    cout << (obj.isPalindrome(head) ? "true" : "false");

    return 0;
}
