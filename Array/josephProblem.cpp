#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int josephus(int n, int k)
    {
        int result = 0;

        for (int i = 2; i <= n; i++)
        {
            result = (result + k) % i;
        }

        return result + 1; // convert to 1-based index
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        Solution obj;
        cout << obj.josephus(n, k) << endl;
    }

    return 0;
}
