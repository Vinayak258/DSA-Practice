#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, bool> counted;
        vector<int> ans;
        for (int i : arr)
        {
            if (counted.find(i) == counted.end())
            {
                ans.push_back(i);
                counted[i] = true;
            }
        }

        return ans;
    }
};

int main()
{

    Solution s1;
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    vector<int> ans = s1.removeDuplicate(arr);
    cout << "Unique elements are: ";
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}