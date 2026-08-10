#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxTask(vector<int> &h, vector<int> &l)
{
    int n = h.size();

    // prev2 = answer up to day i-2
    // prev1 = answer up to day i-1
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < n; i++)
    {

        // Option 1: Do nothing
        int nothing = prev1;

        // Option 2: Do low-effort task
        int low = prev1 + l[i];

        // Option 3: Do high-effort task
        // Previous day must be empty, so use prev2
        int high = prev2 + h[i];

        int current = max({nothing, low, high});

        // Move to next day
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main()
{

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> h(n);
    vector<int> l(n);

    cout << "Enter high-effort tasks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << "Enter low-effort tasks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    int answer = maxTask(h, l);

    cout << "Maximum tasks = " << answer << endl;

    return 0;
}