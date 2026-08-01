#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    // Base case
    if (i == j)
    {
        return nums[i];
    }

    // If already calculated
    if (dp[i][j] != INT_MIN)
    {
        return dp[i][j];
    }

    // Choose left element
    int left = nums[i] - solve(i + 1, j, nums, dp);

    // Choose right element
    int right = nums[j] - solve(i, j - 1, nums, dp);

    // Store maximum score difference
    dp[i][j] = max(left, right);

    return dp[i][j];
}

bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

    int result = solve(0, n - 1, nums, dp);

    return result >= 0;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    if (predictTheWinner(nums))
    {
        cout << "Player 1 can win." << endl;
    }
    else
    {
        cout << "Player 1 cannot win." << endl;
    }

    return 0;
}