#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arrayRankTransform(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
        return {};

    // Store indices
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i;

    // Sort indices based on corresponding array values
    sort(idx.begin(), idx.end(), [&](int a, int b)
         { return arr[a] < arr[b]; });

    vector<int> ans(n);

    int rank = 1;
    ans[idx[0]] = rank;

    for (int i = 1; i < n; i++)
    {
        if (arr[idx[i]] != arr[idx[i - 1]])
            rank++;

        ans[idx[i]] = rank;
    }

    return ans;
}

int main()
{
    vector<int> arr = {40, 10, 20, 30, 20};

    vector<int> ans = arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}