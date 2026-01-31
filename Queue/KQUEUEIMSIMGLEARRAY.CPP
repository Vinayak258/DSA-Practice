#include <bits/stdc++.h>
using namespace std;

class kQueues
{
private:
    int n, k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

public:
    kQueues(int n, int k)
    {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize queues as empty
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    void enqueue(int x, int i)
    {
        if (freeSpot == -1)
            return;

        int index = freeSpot;
        freeSpot = next[index];

        if (front[i] == -1)
        {
            front[i] = index;
        }
        else
        {
            next[rear[i]] = index;
        }

        next[index] = -1;
        rear[i] = index;
        arr[index] = x;
    }

    int dequeue(int i)
    {
        if (front[i] == -1)
            return -1;

        int index = front[i];
        front[i] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        if (front[i] == -1)
        {
            rear[i] = -1;
        }

        return arr[index];
    }

    bool isEmpty(int i)
    {
        return front[i] == -1;
    }

    bool isFull()
    {
        return freeSpot == -1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    kQueues obj(n, k);

    vector<int> output;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x, i;
            cin >> x >> i;
            obj.enqueue(x, i);
        }
        else if (type == 2)
        {
            int i;
            cin >> i;
            output.push_back(obj.dequeue(i));
        }
        else if (type == 3)
        {
            int i;
            cin >> i;
            output.push_back(obj.isEmpty(i));
        }
        else if (type == 4)
        {
            output.push_back(obj.isFull());
        }
    }

    for (int val : output)
        cout << val << " ";

    return 0;
}
