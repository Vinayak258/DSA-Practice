#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kBitFlips(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> isFlipped(n, 0);

        int flip = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            if (i >= k)
                flip ^= isFlipped[i - k];

            if (flip % 2 == arr[i])
            {

                if (i + k > n)
                    return -1;

                isFlipped[i] = 1;
                flip ^= 1;
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter binary array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    int result = obj.kBitFlips(arr, k);

    cout << "Minimum flips required: " << result << endl;

    return 0;
}