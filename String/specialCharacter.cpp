#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> lower(26, 0), upper(26, 0);

        // Traverse the string
        for (char ch : word)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                lower[ch - 'a'] = 1;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                upper[ch - 'A'] = 1;
            }
        }

        int count = 0;

        // Count characters present in both lowercase and uppercase
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] && upper[i])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    string word;

    cout << "Enter the string: ";
    cin >> word;

    int result = obj.numberOfSpecialChars(word);

    cout << "Number of special characters: " << result << endl;

    return 0;
}