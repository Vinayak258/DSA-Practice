#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {

        vector<int> ans;

        for (int num : nums)
        {

            string s = to_string(num);

            for (char ch : s)
            {
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
};

int main()
{

    vector<int> nums = {13, 25, 83, 77};

    Solution obj;

    vector<int> result = obj.separateDigits(nums);

    cout << "Separated Digits: ";

    for (int digit : result)
    {
        cout << digit << " ";
    }

    cout << endl;

    return 0;
}