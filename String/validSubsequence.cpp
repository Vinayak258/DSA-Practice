#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        // last[i] = index in word1 where word2[i] can be matched
        // while matching word2 from right to left.
        vector<int> last(m, -1);

        int word2Index = m - 1;

        // Find a subsequence of word2 from right to left.
        for (int word1Index = n - 1;
             word1Index >= 0 && word2Index >= 0;
             word1Index--)
        {

            if (word1[word1Index] == word2[word2Index])
            {
                last[word2Index] = word1Index;
                word2Index--;
            }
        }

        vector<int> result(m);

        // Whether we have already used our one allowed modification.
        bool usedChange = false;

        word2Index = 0;

        // Greedily choose the smallest possible index.
        for (int word1Index = 0;
             word1Index < n && word2Index < m;
             word1Index++)
        {

            char currentChar = word1[word1Index];
            char requiredChar = word2[word2Index];

            // Case 1: Characters already match.
            bool charactersMatch = currentChar == requiredChar;

            // Case 2: Use the one allowed modification.
            bool canUseChange =
                !usedChange &&
                (word2Index == m - 1 ||
                 word1Index < last[word2Index + 1]);

            if (charactersMatch || canUseChange)
            {

                result[word2Index] = word1Index;

                // Mark that we used our one mismatch.
                if (!charactersMatch)
                {
                    usedChange = true;
                }

                word2Index++;
            }
        }

        // Couldn't match all characters.
        if (word2Index < m)
        {
            return {};
        }

        return result;
    }
};

int main()
{
    Solution obj;

    string word1, word2;

    cout << "Enter word1: ";
    cin >> word1;

    cout << "Enter word2: ";
    cin >> word2;

    vector<int> result = obj.validSequence(word1, word2);

    if (result.empty())
    {
        cout << "No valid sequence exists." << endl;
    }
    else
    {
        cout << "Valid sequence: ";

        for (int index : result)
        {
            cout << index << " ";
        }

        cout << endl;
    }

    return 0;
}