#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(vector<int> &arr)
    {
        long long req = 0;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            req = (req + arr[i] + 1) / 2; // ceil((req + arr[i]) / 2)
        }

        return (int)req;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.find(arr) << "\n";
    }

    return 0;
}