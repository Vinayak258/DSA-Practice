
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int beautySum(string &s)
    {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                ans += maxi - mini;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s;

    cout << "Enter a lowercase string: ";
    cin >> s;

    cout << "Sum of Beauty of All Substrings: "
         << sol.beautySum(s) << endl;

    return 0;
}
