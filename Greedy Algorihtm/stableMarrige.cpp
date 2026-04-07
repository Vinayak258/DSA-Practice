#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women)
    {
        int n = men.size();

        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++)
        {
            for (int i = 0; i < n; i++)
            {
                rank[w][women[w][i]] = i;
            }
        }

        vector<int> wife(n, -1);        // wife[m] = matched woman for man m
        vector<int> husband(n, -1);     // husband[w] = matched man for woman w
        vector<int> nextProposal(n, 0); // next woman each man proposes to

        queue<int> freeMen;
        for (int m = 0; m < n; m++)
        {
            freeMen.push(m);
        }

        while (!freeMen.empty())
        {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][nextProposal[m]];
            nextProposal[m]++;

            // woman is free
            if (husband[w] == -1)
            {
                husband[w] = m;
                wife[m] = w;
            }
            else
            {
                int current = husband[w];

                // woman prefers new man
                if (rank[w][m] < rank[w][current])
                {
                    husband[w] = m;
                    wife[m] = w;

                    wife[current] = -1;
                    freeMen.push(current);
                }
                else
                {
                    // reject
                    freeMen.push(m);
                }
            }
        }

        return wife;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> men(n, vector<int>(n));
    vector<vector<int>> women(n, vector<int>(n));

    // input men preferences
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> men[i][j];
        }
    }

    // input women preferences
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> women[i][j];
        }
    }

    Solution obj;
    vector<int> ans = obj.stableMarriage(men, women);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}