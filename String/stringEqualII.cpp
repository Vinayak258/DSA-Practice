#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        vector<int> even1(26, 0), odd1(26, 0);
        vector<int> even2(26, 0), odd2(26, 0);

        for (int i = 0; i < s1.size(); i++)
        {
            if (i % 2 == 0)
            {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }
            else
            {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        return (even1 == even2 && odd1 == odd2);
    }
};

int main()
{
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    Solution obj;

    if (obj.checkStrings(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}