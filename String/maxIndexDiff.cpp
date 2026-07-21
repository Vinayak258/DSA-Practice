#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maxIndexDifference(string &s)
    {
        // mx[i] stores the farthest reachable index
        // starting from character ('a' + i)
        vector<int> mx(26, -1);

        int ans = -1;

        // Traverse from right to left
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int ch = s[i] - 'a';

            // By default, we can end at the current index
            int bestEnd = i;

            // If the next alphabet exists on the right,
            // inherit its farthest reachable index
            if (ch < 25 && mx[ch + 1] != -1)
            {
                bestEnd = mx[ch + 1];
            }

            // Update the best reachable index for this character
            mx[ch] = max(mx[ch], bestEnd);

            // If current character is 'a', update answer
            if (ch == 0)
            {
                ans = max(ans, bestEnd - i);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    cout << obj.maxIndexDifference(s) << endl;

    return 0;
}