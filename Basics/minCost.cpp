
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {

        long long option1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        long long common = min(need1, need2);

        long long option2 = 1LL * common * costBoth + 1LL * (need1 - common) * cost1 + 1LL * (need2 - common) * cost2;

        long long option3 = 1LL * max(need1, need2) * costBoth;

        return min({option1, option2, option3});
    }
};

int main()
{
    int cost1, cost2, costBoth, need1, need2;

    cin >> cost1 >> cost2 >> costBoth >> need1 >> need2;

    Solution obj;

    cout << obj.minimumCost(cost1, cost2, costBoth, need1, need2) << endl;

    return 0;
}
