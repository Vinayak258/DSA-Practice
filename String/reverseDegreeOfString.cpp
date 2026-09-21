#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int reverseDegree(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // Reverse alphabet value:
            // a = 26, b = 25, ..., z = 1
            int value = 26 - (s[i] - 'a');

            // Position is 1-indexed
            int position = i + 1;

            ans += value * position;
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    int result = obj.reverseDegree(s);

    cout << result << endl;

    return 0;
}