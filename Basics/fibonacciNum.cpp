#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        int a = 0;
        int b = 1;
        int count = 2;

        int c = a + b;
        while (count < n)
        {
            a = b;
            b = c;
            c = a + b;
            count++;
        }

        return c;
    }
};

int main()
{
    Solution s1;
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << "Fibonacii at n is : " << s1.fib(n) << endl;

    return 0;
}