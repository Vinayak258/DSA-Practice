#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> divisors(int n)
    {
        vector<int> ans;
        if (n < 1)
            return ans;

        int right = n;
        for (int i = 1; i <= right; i++)
        {
            if (n % i == 0)
            {
                right = max(n / i, i);
                ans.push_back(i);
            }
        }

        for (int i : ans)
        {
            if (n / i != i)
            {
                ans.push_back(n / i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    int num;
    cout << "Enter number : ";
    cin >> num;

    Solution s1;
    vector<int> ans = s1.divisors(num);

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}