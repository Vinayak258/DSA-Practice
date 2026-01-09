#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countAtMostK(vector<int> &arr, int k)
    {
        if (k == 0)
            return 0;

        unordered_map<int, int> freq;
        int left = 0;
        long long count = 0;
        int n = arr.size();

        for (int right = 0; right < n; right++)
        {
            freq[arr[right]]++;

            // Shrink the window if distinct > k
            while ((int)freq.size() > k)
            {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0)
                {
                    freq.erase(arr[left]);
                }
                left++;
            }

            // Add all subarrays ending at right
            count += (right - left + 1);
        }

        return (int)count;
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
    cout << obj.countAtMostK(arr, k) << endl;

    return 0;
}
