#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperation(int n)
    {
        int ans = 0;

        while (n > 0)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n--;
            }
            ans++;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.minOperation(n) << endl;

    return 0;
}