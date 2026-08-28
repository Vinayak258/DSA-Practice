#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string result = "";
    char midChar = '$';
    int half = 0;

    bool solve(string &curr, vector<int> &count,
               string &target, int i, bool greater)
    {

        // Left half is completely constructed
        if (i == half)
        {

            string leftHalf = curr;

            // Construct right half
            string rightHalf = leftHalf;
            reverse(rightHalf.begin(), rightHalf.end());

            string candidate = leftHalf;

            // Add middle character if length is odd
            if (midChar != '$')
                candidate += midChar;

            // Add right half
            candidate += rightHalf;

            // We need strictly greater than target
            if (candidate > target)
            {
                result = candidate;
                return true;
            }

            return false;
        }

        // Try characters in lexicographical order
        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            // Character not available
            if (count[ch - 'a'] == 0)
                continue;

            // If we haven't become greater yet,
            // we cannot choose a character smaller than target[i]
            if (!greater && ch < target[i])
                continue;

            // Choose character
            curr.push_back(ch);
            count[ch - 'a']--;

            // Check whether we are now greater than target
            bool isGreater = greater || (ch > target[i]);

            // Continue constructing
            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            // Backtrack
            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target)
    {

        // Reset member variables
        result = "";
        midChar = '$';

        int n = s.length();

        // Count characters
        vector<int> count(26, 0);

        for (char ch : s)
            count[ch - 'a']++;

        // Check if palindrome is possible
        int oddCount = 0;

        for (int c = 0; c < 26; c++)
        {

            if (count[c] % 2 == 1)
            {
                oddCount++;
                midChar = char('a' + c);
            }
        }

        // More than one odd frequency -> no palindrome possible
        if (oddCount > 1)
            return "";

        // We only need half of each character
        vector<int> halfCount(26, 0);

        for (int c = 0; c < 26; c++)
            halfCount[c] = count[c] / 2;

        // Length of left half
        half = n / 2;

        string curr;

        solve(curr, halfCount, target, 0, false);

        return result;
    }
};

int main()
{

    Solution obj;

    // Example 1
    string s1 = "baba";
    string target1 = "abba";

    cout << "Input: s = " << s1
         << ", target = " << target1 << endl;

    cout << "Output: "
         << obj.lexPalindromicPermutation(s1, target1)
         << endl;

    // Example 2
    string s2 = "baba";
    string target2 = "bbaa";

    cout << "\nInput: s = " << s2
         << ", target = " << target2 << endl;

    cout << "Output: "
         << obj.lexPalindromicPermutation(s2, target2)
         << endl;

    // Example 3
    string s3 = "abc";
    string target3 = "abb";

    cout << "\nInput: s = " << s3
         << ", target = " << target3 << endl;

    cout << "Output: "
         << obj.lexPalindromicPermutation(s3, target3)
         << endl;

    // Example 4
    string s4 = "aac";
    string target4 = "abb";

    cout << "\nInput: s = " << s4
         << ", target = " << target4 << endl;

    cout << "Output: "
         << obj.lexPalindromicPermutation(s4, target4)
         << endl;

    return 0;
}