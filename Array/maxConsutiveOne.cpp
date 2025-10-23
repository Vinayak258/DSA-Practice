#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxConOnes(vector<int> &a)
    {
        int maxLne = 0;
        int currlen = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                currlen++;
                maxLne = max(maxLne, currlen);
            }
            else
            {
                currlen = 0;
            }
        }
        return maxLne;
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = s1.maxConOnes(arr);
    cout << "Maximum consutive ones : " << ans << endl;

    return 0;
}