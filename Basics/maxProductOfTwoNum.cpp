#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx1 = 0, mx2 = 0;

        for (int x : nums)
        {
            if (x >= mx1)
            {
                mx2 = mx1;
                mx1 = x;
            }
            else if (x > mx2)
            {
                mx2 = x;
            }
        }

        return (mx1 - 1) * (mx2 - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    cout << obj.maxProduct(nums) << endl;

    return 0;
}