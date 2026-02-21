#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> count(n + 1, 0);

        // Count citation frequencies
        for (int c : citations)
        {
            if (c >= n)
                count[n]++;
            else
                count[c]++;
        }

        int papers = 0;

        // Find H-index
        for (int i = n; i >= 0; i--)
        {
            papers += count[i];
            if (papers >= i)
                return i;
        }

        return 0;
    }
};

int main()
{
    int n;
    cin >> n; // number of papers

    vector<int> citations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> citations[i]; // input citations
    }

    Solution obj;
    cout << obj.hIndex(citations) << endl;

    return 0;
}