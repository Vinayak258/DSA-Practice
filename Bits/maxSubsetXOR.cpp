#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubsetXOR(vector<int> &arr)
    {
        int n = arr.size();
        int index = 0;

        // Build XOR Basis
        for (int bit = 31; bit >= 0; bit--)
        {

            // Find an element with current bit set
            int pivot = -1;
            for (int i = index; i < n; i++)
            {
                if (arr[i] & (1 << bit))
                {
                    pivot = i;
                    break;
                }
            }

            if (pivot == -1)
                continue;

            // Bring pivot to current position
            swap(arr[index], arr[pivot]);

            // Eliminate this bit from all other numbers
            for (int i = 0; i < n; i++)
            {
                if (i != index && (arr[i] & (1 << bit)))
                {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        // Compute maximum XOR possible
        int ans = 0;
        for (int x : arr)
        {
            ans = max(ans, ans ^ x);
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    cout << "Maximum Subset XOR = " << obj.maxSubsetXOR(arr) << endl;

    return 0;
}