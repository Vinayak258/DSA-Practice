#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> maap;

        for (int i = 0; i < s.length(); i++)
        {
            maap[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++)
        {
            maap[t[i]]--;
        }

        for (auto it = maap.begin(); it != maap.end(); it++)
        {
            if (it->second != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (sol.isAnagram(s, t))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are NOT anagrams." << endl;
    }

    return 0;
}
