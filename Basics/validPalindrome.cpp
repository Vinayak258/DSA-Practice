#include <string>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool solve(string s, int i, int n)
    {
        if (i >= n / 2)
            return true;

        if (s[i] != s[n - i - 1])
        {
            return false;
        }
        return solve(s, ++i, n);
    }

public:
    bool isPalindromeIterative(string s)
    {

        int left = 0, right = s.size() - 1;

        while (left < right)
        {

            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            if (towlower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
    bool isPalindrome(string s)
    {
        int n = s.length();
        if (n <= 1)
            return true;

        string cleaned = "";
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                cleaned += tolower(ch);
            }
        }
        return solve(cleaned, 0, cleaned.size());
    }
};

int main()
{
    Solution s1;
    string str;
    cout << "Enter the string : ";
    cin >> str;

    if (s1.isPalindromeIterative(str))
    {
        cout << "Yes , string is palindrome" << endl;
    }
    else
    {
        cout << "No, string is not palindrome " << endl;
    }

    return 0;
}