#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string ans = "";
    int count = 0;

    void dfs(string &curr, int n, int k)
    {
        if (curr.size() == n)
        {
            count++;
            if (count == k)
                ans = curr;
            return;
        }

        for (char c : {'a', 'b', 'c'})
        {
            if (!curr.empty() && curr.back() == c)
                continue;

            curr.push_back(c);
            dfs(curr, n, k);
            curr.pop_back();

            if (!ans.empty())
                return;
        }
    }

    string getHappyString(int n, int k)
    {
        string curr = "";
        dfs(curr, n, k);
        return ans;
    }
};

int main()
{
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution obj;
    string result = obj.getHappyString(n, k);

    if (result == "")
        cout << "No such happy string exists\n";
    else
        cout << "Kth happy string: " << result << endl;

    return 0;
}