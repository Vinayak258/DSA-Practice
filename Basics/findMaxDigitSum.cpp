#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int digitSum(int x)
    {
        int sum = 0;

        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int findMax(int n)
    {
        int ans = n;

        string s = to_string(n);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                continue;

            string temp = s;

            temp[i]--;

            for (int j = i + 1; j < s.size(); j++)
            {
                temp[j] = '9';
            }

            int candidate = stoi(temp);

            if (digitSum(candidate) > digitSum(ans) ||
                (digitSum(candidate) == digitSum(ans) && candidate > ans))
            {
                ans = candidate;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter n: ";
    cin >> n;

    int result = obj.findMax(n);

    cout << "Number with maximum digit sum: " << result << endl;
    cout << "Maximum digit sum: " << obj.digitSum(result) << endl;

    return 0;
}