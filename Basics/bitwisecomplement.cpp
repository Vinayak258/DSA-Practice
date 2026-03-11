#include <iostream>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0)
            return 1;

        int mask = 0;
        int temp = n;

        while (temp > 0)
        {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return n ^ mask;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution obj;
    cout << obj.bitwiseComplement(n) << endl;

    return 0;
}