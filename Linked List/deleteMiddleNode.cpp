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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};

// Function to insert a node at the end
void insertNode(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        head = new ListNode(val);
        return;
    }

    ListNode *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new ListNode(val);
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = nullptr;

    // Example: [1,3,4,7,1,2,6]
    int arr[] = {1, 3, 4, 7, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        insertNode(head, arr[i]);
    }

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}