#include <iostream>
using namespace std;

class Solution
{
public:
    int countFriendsPairings(int n)
    {
        if (n <= 1)
            return 1;

        long long prev2 = 1; // dp[0]
        long long prev1 = 1; // dp[1]

        for (int i = 2; i <= n; i++)
        {
            long long curr = prev1 + (long long)(i - 1) * prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.countFriendsPairings(n) << endl;

    return 0;
}