#include <iostream>
using namespace std;

class Solution
{
public:
    int countStrings(int n)
    {
        if (n == 1)
            return 2;
        if (n == 2)
            return 3;

        int a = 2; // f(1)
        int b = 3; // f(2)

        for (int i = 3; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.countStrings(n) << endl;

    return 0;
}