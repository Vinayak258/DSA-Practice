#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {

        // Overlap on X-axis
        bool xOverlap = rec1[0] < rec2[2] &&
                        rec2[0] < rec1[2];

        // Overlap on Y-axis
        bool yOverlap = rec1[1] < rec2[3] &&
                        rec2[1] < rec1[3];

        return xOverlap && yOverlap;
    }
};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> rec1(4), rec2(4);

    // Input:
    // x1 y1 x2 y2
    cin >> rec1[0] >> rec1[1] >> rec1[2] >> rec1[3];

    // Input:
    // x1 y1 x2 y2
    cin >> rec2[0] >> rec2[1] >> rec2[2] >> rec2[3];

    Solution obj;

    bool ans = obj.isRectangleOverlap(rec1, rec2);

    cout << boolalpha << ans << '\n';

    return 0;
}