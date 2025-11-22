#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 0)
            return 0;

        int longst = 1;
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            { // start of a sequence
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end())
                {
                    x++;
                    count++;
                }

                longst = max(longst, count);
            }
        }

        return longst;
    }
};

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    int answer = sol.longestConsecutive(nums);

    cout << "Longest consecutive sequence length: " << answer << endl;

    return 0;
}
