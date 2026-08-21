#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int transform(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();

        // Different lengths -> impossible
        if (n != m)
            return -1;

        // Check whether both strings contain
        // the same characters with the same frequency
        int freq[256] = {0};

        for (int i = 0; i < n; i++)
        {
            freq[s1[i]]++;
            freq[s2[i]]--;
        }

        for (int i = 0; i < 256; i++)
        {
            if (freq[i] != 0)
                return -1;
        }

        // Greedy approach
        int ans = 0;

        int i = n - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0)
        {

            // If characters don't match,
            // s1[i] must be moved to the front
            while (i >= 0 && s1[i] != s2[j])
            {
                ans++;
                i--;
            }

            // Matching character can stay in its position
            if (i >= 0)
            {
                i--;
                j--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    int result = obj.transform(s1, s2);

    cout << "Minimum steps: " << result << endl;

    return 0;
}