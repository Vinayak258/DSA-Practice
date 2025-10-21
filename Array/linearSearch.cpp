#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool linearSearch(vector<int> arr, int target)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == target)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    Solution s1;
    int n;
    cout << "Enter size : ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tar;
    cout << "Enter element to be searched : ";
    cin >> tar;

    if (s1.linearSearch(arr, tar))
    {
        cout << "Element found " << endl;
    }
    else
    {
        cout << "Element not Found " << endl;
    }
    return 0;
}