#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        vector<int> freq(10, 0);

        // Count frequency of each digit
        for (int d : digits)
        {
            freq[d]++;
        }

        int ans = 0;

        // Check every 3-digit even number
        for (int num = 100; num <= 998; num += 2)
        {

            int x = num;

            int ones = x % 10;
            x /= 10;

            int tens = x % 10;
            x /= 10;

            int hundreds = x;

            // Count digits required for this number
            vector<int> need(10, 0);

            need[ones]++;
            need[tens]++;
            need[hundreds]++;

            bool possible = true;

            // Check if digits are available
            for (int d = 0; d <= 9; d++)
            {
                if (need[d] > freq[d])
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{

    int n;

    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);

    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }

    Solution obj;

    int result = obj.totalNumbers(digits);

    cout << "Number of distinct 3-digit even numbers: "
         << result << endl;

    return 0;
}