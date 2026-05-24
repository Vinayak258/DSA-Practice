#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coin(vector<int> &arr)
    {
        int i = 0;
        int j = arr.size() - 1;

        // Continue removing coins until one remains
        while (i < j)
        {
            if (arr[i] >= arr[j])
            {
                i++; // remove left coin
            }
            else
            {
                j--; // remove right coin
            }
        }

        return arr[i];
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

    cout << obj.coin(arr) << endl;

    return 0;
}