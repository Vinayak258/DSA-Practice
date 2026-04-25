#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> reducePairs(vector<int> &arr)
    {
        vector<int> st;

        for (int x : arr)
        {
            bool destroyed = false;

            while (!st.empty() && st.back() * x < 0)
            {
                int top = st.back();

                if (abs(top) > abs(x))
                {
                    // current element gets destroyed
                    destroyed = true;
                    break;
                }
                else if (abs(top) < abs(x))
                {
                    // top element gets removed
                    st.pop_back();
                }
                else
                {
                    // equal absolute values → both removed
                    st.pop_back();
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
            {
                st.push_back(x);
            }
        }

        return st;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.reducePairs(arr);

    // Print result
    if (result.empty())
    {
        cout << "[]";
    }
    else
    {
        for (int x : result)
        {
            cout << x << " ";
        }
    }

    return 0;
}