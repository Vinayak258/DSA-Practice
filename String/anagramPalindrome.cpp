#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool canFormPalindrome(string &s)
    {
        int freq[26] = {0};

        // Count frequency of each character
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        // Count characters with odd frequency
        int oddCount = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
            {
                oddCount++;
            }
        }

        // Check condition
        return oddCount <= 1;
    }
};

int main()
{
    Solution obj;
    string s;

    // Input
    cout << "Enter string: ";
    cin >> s;

    // Function call
    if (obj.canFormPalindrome(s))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}