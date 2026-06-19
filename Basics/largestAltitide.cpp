#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int altitude = 0;
        int maxAlt = 0;

        for (int x : gain)
        {
            altitude += x;
            maxAlt = max(maxAlt, altitude);
        }

        return maxAlt;
    }
};

int main()
{
    int n;
    cout << "Enter the size of gain array: ";
    cin >> n;

    vector<int> gain(n);

    cout << "Enter the elements of gain array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> gain[i];
    }

    Solution sol;
    cout << "Highest Altitude: " << sol.largestAltitude(gain) << endl;

    return 0;
}