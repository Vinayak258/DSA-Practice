#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeSpaces(string &s)
    {
        string ans = "";

        for (char ch : s)
        {
            if (ch != ' ')
            {
                ans += ch;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string result = obj.removeSpaces(s);

    cout << "String after removing spaces: " << result << endl;

    return 0;
}