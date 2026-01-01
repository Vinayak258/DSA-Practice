#include <bits/stdc++.h>
using namespace std;

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
    Node *intersectPoint(Node *head1, Node *head2)
    {
        Node *p1 = head1;
        Node *p2 = head2;

        while (p1 != p2)
        {
            p1 = (p1 == NULL) ? head2 : p1->next;
            p2 = (p2 == NULL) ? head1 : p2->next;
        }
        return p1;
    }
};

int main()
{
    /*
        Example:
        head1: 10 -> 15 -> 30
        head2: 3 -> 6 -> 9 -> 15 -> 30
        Intersection point: 15
    */

    // Common part
    Node *common = new Node(15);
    common->next = new Node(30);

    // First list
    Node *head1 = new Node(10);
    head1->next = common;

    // Second list
    Node *head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = common;

    Solution obj;
    Node *intersection = obj.intersectPoint(head1, head2);

    if (intersection)
        cout << "Intersection Point: " << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
