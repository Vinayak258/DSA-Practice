#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string profession(int level, int pos)
    {

        // Count set bits in (pos - 1)
        int cnt = __builtin_popcount(pos - 1);

        // Even number of flips -> Engineer
        // Odd number of flips  -> Doctor
        return (cnt % 2 == 0) ? "Engineer" : "Doctor";
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int level, pos;
        cin >> level >> pos;

        Solution obj;
        cout << obj.profession(level, pos) << endl;
    }

    return 0;
}