#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(int start, int n, int num, vector<int> &ans)
    {
        if (n == 0)
        {
            ans.push_back(num);
            return;
        }

        for (int d = start; d <= 9; d++)
        {
            solve(d + 1, n - 1, num * 10 + d, ans);
        }
    }

    vector<int> increasingNumbers(int n)
    {
        vector<int> ans;

        if (n == 1)
        {
            for (int i = 0; i <= 9; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        if (n > 9)
        {
            return ans;
        }

        solve(1, n, 0, ans);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    vector<int> ans = obj.increasingNumbers(n);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}