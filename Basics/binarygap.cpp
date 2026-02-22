#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int binaryGap(int n)
    {
        int last = -1;
        int pos = 0;
        int ans = 0;

        while (n > 0)
        {
            if (n & 1)
            {
                if (last != -1)
                {
                    ans = max(ans, pos - last);
                }
                last = pos;
            }
            n >>= 1;
            pos++;
        }
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    Solution obj;
    int result = obj.binaryGap(n);

    cout << "Maximum binary gap: " << result << endl;
    return 0;
}