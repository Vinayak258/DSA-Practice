#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        int n = arr.size();

        // Step 1: Count total number of 1s
        int k = 0;
        for (int x : arr)
        {
            if (x == 1)
                k++;
        }

        // Step 2: If no 1s present
        if (k == 0)
            return -1;

        // Step 3: Count 1s in first window of size k
        int currOnes = 0;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] == 1)
                currOnes++;
        }

        int maxOnes = currOnes;

        // Step 4: Slide the window
        for (int i = k; i < n; i++)
        {
            if (arr[i] == 1)
                currOnes++;
            if (arr[i - k] == 1)
                currOnes--;

            maxOnes = max(maxOnes, currOnes);
        }

        // Step 5: Minimum swaps required
        return k - maxOnes;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 0, 1, 0, 1};
    cout << obj.minSwaps(arr) << endl; // Output: 1

    return 0;
}