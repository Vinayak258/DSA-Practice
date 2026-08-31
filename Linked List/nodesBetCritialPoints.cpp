#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {

        // We need at least 3 nodes to have a critical point
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return {-1, -1};
        }

        ListNode *prev = head;
        ListNode *curr = head->next;

        int position = 1;

        int firstCritical = -1;
        int previousCritical = -1;

        int minDistance = INT_MAX;

        while (curr != nullptr && curr->next != nullptr)
        {

            ListNode *next = curr->next;

            // Check for local maximum
            bool localMax =
                (curr->val > prev->val &&
                 curr->val > next->val);

            // Check for local minimum
            bool localMin =
                (curr->val < prev->val &&
                 curr->val < next->val);

            // Current node is a critical point
            if (localMax || localMin)
            {

                // First critical point
                if (firstCritical == -1)
                {
                    firstCritical = position;
                }

                // If this is not the first critical point,
                // calculate distance from previous critical point
                if (previousCritical != -1)
                {
                    minDistance = min(
                        minDistance,
                        position - previousCritical);
                }

                previousCritical = position;
            }

            prev = curr;
            curr = next;
            position++;
        }

        // Fewer than two critical points
        if (firstCritical == -1 || previousCritical == firstCritical)
        {
            return {-1, -1};
        }

        // Maximum distance = last critical point - first critical point
        int maxDistance = previousCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};

// Function to create linked list
ListNode *createList(vector<int> arr)
{

    if (arr.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main()
{

    // Example:
    // 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2

    vector<int> arr = {5, 3, 1, 2, 5, 1, 2};

    // Create linked list
    ListNode *head = createList(arr);

    // Create Solution object
    Solution obj;

    // Call function
    vector<int> answer = obj.nodesBetweenCriticalPoints(head);

    // Print answer
    cout << "[" << answer[0] << ", " << answer[1] << "]" << endl;

    return 0;
}