#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        string left = "";
        char mid = '\0';

        // Build left half and find middle character (if any)
        for (int i = 0; i < 26; i++)
        {
            left.append(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1)
            {
                mid = char('a' + i);
            }
        }

        // Right half is reverse of left half
        string right = left;
        reverse(right.begin(), right.end());

        // Construct answer
        if (mid != '\0')
            return left + mid + right;

        return left + right;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter the palindrome string: ";
    cin >> s;

    cout << "Lexicographically smallest palindrome: "
         << obj.smallestPalindrome(s) << endl;

    return 0;
}