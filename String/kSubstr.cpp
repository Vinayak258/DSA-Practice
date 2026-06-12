#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kSubstr(string &s, int k)
    {
        int n = s.size();

        if (n % k != 0)
            return false;

        int blocks = n / k;
        unordered_map<string, int> freq;
        int maxFreq = 0;

        for (int i = 0; i < n; i += k)
        {
            string block = s.substr(i, k);
            maxFreq = max(maxFreq, ++freq[block]);
        }

        return maxFreq >= blocks - 1;
    }
};

int main()
{
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    if (obj.kSubstr(s, k))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}