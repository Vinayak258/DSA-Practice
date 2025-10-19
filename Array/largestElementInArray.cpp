#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int largestElement(vector<int> &arr)
    {
        int maxi = -1;
        for (int i : arr)
        {
            maxi = (i > maxi) ? i : maxi;
        }
        return maxi;
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
    int largest = s1.largestElement(arr);
    cout << "Largest element is : " << largest << endl;
    return 0;
}