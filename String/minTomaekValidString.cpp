#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open = 0;
        int ans = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                open++;
            }
            else
            {
                if (open > 0)
                {
                    open--;
                }
                else
                {
                    ans++;
                }
            }
        }

        return ans + open;
    }
};

int main()
{
    Solution obj;

    string s;
    cin >> s;

    int result = obj.minAddToMakeValid(s);

    cout << result << endl;

    return 0;
}