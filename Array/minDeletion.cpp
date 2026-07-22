#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& arr) {
        vector<int> lis;

        for (int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }

        return arr.size() - lis.size();
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.minDeletions(arr) << endl;

    return 0;
}