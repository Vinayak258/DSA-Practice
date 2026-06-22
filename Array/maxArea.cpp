#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        long long ans = 0;

        while (left < right)
        {
            long long width = right - left - 1; // bars between them
            long long area = 1LL * min(height[left], height[right]) * width;

            ans = max(ans, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return (int)ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    Solution obj;
    cout << "Maximum Area = " << obj.maxArea(height) << endl;

    return 0;
}