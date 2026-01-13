#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canServe(vector<int> &arr)
    {
        int five = 0;
        int ten = 0;

        for (int note : arr)
        {
            if (note == 5)
            {
                five++;
            }
            else if (note == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else
            { // note == 20
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n; // size of array

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    bool result = obj.canServe(arr);

    if (result)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}
