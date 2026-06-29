#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;

        for (string &s : patterns)
        {
            if (word.find(s) != string::npos)
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    int n;
    cout << "Enter number of patterns: ";
    cin >> n;

    vector<string> patterns(n);

    cout << "Enter the patterns:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> patterns[i];
    }

    string word;
    cout << "Enter the word: ";
    cin >> word;

    Solution obj;
    int result = obj.numOfStrings(patterns, word);

    cout << "Number of patterns that appear as substrings: "
         << result << endl;

    return 0;
}