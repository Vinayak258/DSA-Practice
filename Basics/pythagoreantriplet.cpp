#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {
        const int MAX = 1000;
        vector<int> freq(MAX + 1, 0);

        // count frequencies
        for (int x : arr)
        {
            freq[x]++;
        }

        // check all pairs (a, b)
        for (int a = 1; a <= MAX; a++)
        {
            if (!freq[a])
                continue;

            for (int b = a; b <= MAX; b++)
            {
                if (!freq[b])
                    continue;

                int sum = a * a + b * b;
                int c = (int)sqrt(sum);

                if (c <= MAX && c * c == sum && freq[c])
                {
                    if (a == b && b == c && freq[a] >= 3)
                        return true;
                    if (a == b && freq[a] >= 2 && freq[c] >= 1)
                        return true;
                    if (a != b && freq[a] >= 1 && freq[b] >= 1 && freq[c] >= 1)
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    if (obj.pythagoreanTriplet(arr))
        cout << "True";
    else
        cout << "False";

    return 0;
}