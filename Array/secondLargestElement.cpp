#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int secondlargestElement(vector<int> &arr)
    {
        int maxi = -1;
        for (int i : arr)
        {
            maxi = (i > maxi) ? i : maxi;
        }

        int smaxi = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (smaxi < arr[i] && arr[i] != maxi)
            {
                smaxi = arr[i];
            }
        }

        return smaxi;
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
    int largest = s1.secondlargestElement(arr);
    cout << " Second Largest element is : " << largest << endl;
    return 0;
}