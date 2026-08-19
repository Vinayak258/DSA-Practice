#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countLE(vector<int>& a, long long x) {
        int n = a.size();
        long long cnt = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long sum = 1LL * a[i] + a[j] + a[k];

                if (sum <= x) {
                    cnt += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }

        return cnt;
    }

    long long countTriplets(vector<int>& arr, int l, int r) {
        sort(arr.begin(), arr.end());

        return countLE(arr, r) - countLE(arr, l - 1);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l, r;
    cin >> l >> r;

    Solution obj;

    cout << obj.countTriplets(arr, l, r) << endl;

    return 0;
}