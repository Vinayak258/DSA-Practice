#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int getLastDigit(string &a, string &b)
    {
        // a^0 = 1
        if (b == "0")
            return 1;

        int lastDigit = a.back() - '0';

        // Compute b % 4
        int mod = 0;
        for (char ch : b)
        {
            mod = (mod * 10 + (ch - '0')) % 4;
        }

        if (mod == 0)
            mod = 4;

        int ans = 1;
        for (int i = 0; i < mod; i++)
        {
            ans = (ans * lastDigit) % 10;
        }

        return ans;
    }
};

int main()
{
    string a, b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    Solution obj;
    cout << "Last digit of a^b = " << obj.getLastDigit(a, b) << endl;

    return 0;
}