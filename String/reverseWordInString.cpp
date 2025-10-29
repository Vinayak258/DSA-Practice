#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words (stringstream automatically skips multiple spaces)
        while (ss >> word)
        {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join them with single space
        string result;
        for (int i = 0; i < (int)words.size(); i++)
        {
            if (i > 0)
                result += " ";
            result += words[i];
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s;

    // Taking full line input (including spaces)
    cout << "Enter a string: ";
    getline(cin, s);

    string reversed = sol.reverseWords(s);

    cout << "Reversed words: \"" << reversed << "\"" << endl;

    return 0;
}
