#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, string s)
    {
        vector<int> status(26, 0);

        int occupied = 0;
        int rejected = 0;

        for (char c : s)
        {
            int id = c - 'A';

            // First occurrence = customer arrives
            if (status[id] == 0)
            {

                if (occupied < n)
                {
                    // Computer is available
                    status[id] = 1;
                    occupied++;
                }
                else
                {
                    // No computer available
                    status[id] = 2;
                    rejected++;
                }
            }

            // Second occurrence of a customer who got a computer
            else if (status[id] == 1)
            {
                occupied--;
                status[id] = 0;
            }

            // Second occurrence of a rejected customer
            else
            {
                status[id] = 0;
            }
        }

        return rejected;
    }
};

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    Solution obj;

    cout << obj.solve(n, s) << endl;

    return 0;
}