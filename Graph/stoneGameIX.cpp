#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {

        // Count stones based on their remainder when divided by 3
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int ele : stones)
        {

            if (ele % 3 == 0)
            {
                count0++;
            }
            else if (ele % 3 == 1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }

        // If count of remainder 0 stones is even
        if (count0 % 2 == 0)
        {
            return count1 >= 1 && count2 >= 1;
        }

        // If count of remainder 0 stones is odd
        return abs(count1 - count2) > 2;
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> stones(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }

    Solution obj;

    bool result = obj.stoneGameIX(stones);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}