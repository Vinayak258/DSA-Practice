#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int n = arr.size();
        int zcount = 0;
        int maxlen = 0;
        int s = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zcount++;
            }

            while (zcount > k)
            {
                if (arr[s] == 0)
                {
                    zcount--;
                }
                s++;
            }

            maxlen = max(maxlen, i - s + 1);
        }

        return maxlen;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxOnes(arr, k) << endl;

    return 0;
}
