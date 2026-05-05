#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length and last node
        int n = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            n++;
        }

        // Step 2: Reduce k
        k = k % n;
        if (k == 0)
            return head;

        // Step 3: Make list circular
        tail->next = head;

        // Step 4: Find new tail (n - k - 1 steps)
        int steps = n - k - 1;
        ListNode *newTail = head;
        while (steps--)
        {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Helper function to print list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main()
{
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    int k = 2;

    head = obj.rotateRight(head, k);

    printList(head); // Output: 4 5 1 2 3

    return 0;
}