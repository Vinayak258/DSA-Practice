#include <iostream>
using namespace std;

class Solution
{

public:
    bool isPrime(int n)
    {

        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    Solution s1;
    int n;
    cout << "Enter number : ";
    cin >> n;

    if (s1.isPrime(n))
    {
        cout << "Number is Prime " << endl;
    }
    else
    {
        cout << "Number is not Prime " << endl;
    }
    return 0;
}