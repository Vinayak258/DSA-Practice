#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    void frequencyCount(int arr[], int n)
    {

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        for (auto i : mp)
        {
            cout << i.first << "->" << i.second << endl;
        }
    }
};

int main()
{

    Solution s1;
    int arr[] = {3, 4, 2, 5, 6, 5, 4, 6, 8, 7, 33, 7, 7, 3, 6, 3, 2, 33, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    s1.frequencyCount(arr, n);
    return 0;
}