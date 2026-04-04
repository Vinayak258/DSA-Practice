#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> graycode(int n)
    {
        vector<string> ans;

        int total = 1 << n; // 2^n total gray codes

        for (int i = 0; i < total; i++)
        {
            int gray = i ^ (i >> 1);

            string s = "";
            for (int j = n - 1; j >= 0; j--)
            {
                s += ((gray >> j) & 1) ? '1' : '0';
            }

            ans.push_back(s);
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    vector<string> result = obj.graycode(n);

    for (string code : result)
    {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}