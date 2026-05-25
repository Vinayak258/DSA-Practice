#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkElements(int start, int end, vector<int> &arr)
    {
        unordered_set<int> s(arr.begin(), arr.end());

        for (int i = start; i <= end; i++)
        {
            if (s.find(i) == s.end())
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    int start, end, n;

    cin >> start >> end;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    if (obj.checkElements(start, end, arr))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}