
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstElementKTime(vector<int>& arr, int k) {

        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {

            freq[arr[i]]++;

            if (freq[arr[i]] == k) {
                return arr[i];
            }
        }

        return -1;
    }
};

int main() {

    int n, k;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    Solution obj;

    cout << obj.firstElementKTime(arr, k) << endl;

    return 0;
}
