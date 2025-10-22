#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> unionArray(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            mp[b[i]]++;
        }
        for (auto i : mp)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    int n, m;
    cout << "Enter size of 1st array : ";
    cin >> n;

    vector<int> a(n, 0);

    cout << "Enter array one : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of 2nd array : ";
    cin >> m;
    vector<int> b(m, 0);
    cout << "Enter array two : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> unionArr = s1.unionArray(a, b, a.size(), b.size());

    cout << "Union elements are : ";
    for (int i = 0; i < unionArr.size(); i++)
    {
        cout << unionArr[i] << " ";
    }
    return 0;
}