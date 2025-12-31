#include <bits/stdc++.h>
using namespace std;

/* Linked List Node */
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
private:
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

public:
    Node *addTwoLists(Node *head1, Node *head2)
    {
        // Reverse both lists
        head1 = reverseList(head1);
        head2 = reverseList(head2);

        int carry = 0;
        Node *dummy = new Node(0);
        Node *tail = dummy;

        // Add digits
        while (head1 || head2 || carry)
        {
            int sum = carry;
            if (head1)
            {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2)
            {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        // Reverse result
        Node *result = reverseList(dummy->next);

        // Remove leading zeros
        while (result && result->data == 0 && result->next)
        {
            result = result->next;
        }

        return result;
    }
};

/* Helper function to create linked list from vector */
Node *createList(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *curr = head;
    for (int i = 1; i < v.size(); i++)
    {
        curr->next = new Node(v[i]);
        curr = curr->next;
    }
    return head;
}

/* Helper function to print linked list */
void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example 1: 123 + 999 = 1122
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {9, 9, 9};

    Node *head1 = createList(v1);
    Node *head2 = createList(v2);

    Solution obj;
    Node *result = obj.addTwoLists(head1, head2);

    cout << "Result: ";
    printList(result);

    // Example 2: 63 + 7 = 70
    vector<int> v3 = {6, 3};
    vector<int> v4 = {7};

    head1 = createList(v3);
    head2 = createList(v4);

    result = obj.addTwoLists(head1, head2);

    cout << "Result: ";
    printList(result);

    return 0;
}
