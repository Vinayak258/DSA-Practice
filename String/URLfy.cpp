#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string URLify(string &s)
    {
        string ans;

        for (char ch : s)
        {
            if (ch == ' ')
                ans += "%20";
            else
                ans += ch;
        }

        return ans;
    }
};

int main()
{
    string s;

    // Take full line input including spaces
    getline(cin, s);

    Solution obj;
    cout << obj.URLify(s) << endl;

    return 0;
}