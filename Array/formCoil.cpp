#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> formCoils(int n)
    {
        int N = 4 * n;
        vector<vector<int>> ans(2);

        // First coil
        int r = 0, c = 0;
        ans[0].push_back(1);

        for (int i = 0; i < N - 1; i++)
        {
            r++;
            ans[0].push_back(r * N + c + 1);
        }

        int len = N - 2;
        int turn = 0;

        while (len > 0)
        {
            if (turn % 2 == 0)
            {
                for (int i = 0; i < len; i++)
                {
                    c++;
                    ans[0].push_back(r * N + c + 1);
                }
                for (int i = 0; i < len; i++)
                {
                    r--;
                    ans[0].push_back(r * N + c + 1);
                }
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    c--;
                    ans[0].push_back(r * N + c + 1);
                }
                for (int i = 0; i < len; i++)
                {
                    r++;
                    ans[0].push_back(r * N + c + 1);
                }
            }

            len -= 2;
            turn++;
        }

        // Second coil
        r = N - 1;
        c = N - 1;
        ans[1].push_back(N * N);

        for (int i = 0; i < N - 1; i++)
        {
            r--;
            ans[1].push_back(r * N + c + 1);
        }

        len = N - 2;
        turn = 0;

        while (len > 0)
        {
            if (turn % 2 == 0)
            {
                for (int i = 0; i < len; i++)
                {
                    c--;
                    ans[1].push_back(r * N + c + 1);
                }
                for (int i = 0; i < len; i++)
                {
                    r++;
                    ans[1].push_back(r * N + c + 1);
                }
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    c++;
                    ans[1].push_back(r * N + c + 1);
                }
                for (int i = 0; i < len; i++)
                {
                    r--;
                    ans[1].push_back(r * N + c + 1);
                }
            }

            len -= 2;
            turn++;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    vector<vector<int>> result = obj.formCoils(n);

    cout << "[";
    for (int i = 0; i < 2; i++)
    {
        cout << "[";
        for (int j = 0; j < (int)result[i].size(); j++)
        {
            cout << result[i][j];
            if (j + 1 < (int)result[i].size())
                cout << ", ";
        }
        cout << "]";
        if (i == 0)
            cout << ", ";
    }
    cout << "]\n";

    return 0;
}