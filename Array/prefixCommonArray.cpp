#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();

        vector<int> freq(n + 1, 0);
        vector<int> ans(n);

        int common = 0;

        for (int i = 0; i < n; i++)
        {

            // Mark element from A
            freq[A[i]]++;
            if (freq[A[i]] == 2)
                common++;

            // Mark element from B
            freq[B[i]]++;
            if (freq[B[i]] == 2)
                common++;

            ans[i] = common;
        }

        return ans;
    }
};

int main()
{
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    Solution obj;
    vector<int> result = obj.findThePrefixCommonArray(A, B);

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}