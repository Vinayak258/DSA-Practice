#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMoves(vector<int> &chairs, vector<int> &passengers)
    {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());

        int moves = 0;
        for (int i = 0; i < chairs.size(); i++)
        {
            moves += abs(chairs[i] - passengers[i]);
        }

        return moves;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> chairs(n), passengers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> chairs[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> passengers[i];
    }

    Solution obj;
    cout << obj.findMoves(chairs, passengers) << endl;

    return 0;
}
