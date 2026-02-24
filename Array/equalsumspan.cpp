#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2)
    {
        unordered_map<int, int> firstIndex;
        int prefix = 0;
        int maxLen = 0;

        // prefix sum 0 before starting
        firstIndex[0] = -1;

        for (int i = 0; i < a1.size(); i++)
        {
            prefix += (a1[i] - a2[i]);

            if (firstIndex.find(prefix) != firstIndex.end())
            {
                maxLen = max(maxLen, i - firstIndex[prefix]);
            }
            else
            {
                firstIndex[prefix] = i;
            }
        }

        return maxLen;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> a1(n), a2(n);

    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < n; i++)
        cin >> a2[i];

    Solution obj;
    cout << obj.equalSumSpan(a1, a2) << endl;

    return 0;
}