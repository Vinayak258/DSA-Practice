#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {

        vector<int> ans;
        string str = "123456789";

        for (int len = 2; len <= 9; len++)
        {

            for (int i = 0; i + len <= 9; i++)
            {
                int num = stoi(str.substr(i, len));

                if (num >= low && num <= high)
                {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};

int main()
{

    int low, high;

    cout << "Enter low high : ";
    cin >> low >> high;

    Solution s1;

    vector<int> ans = s1.sequentialDigits(low, high);

    for (int i = 0; i <= ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}