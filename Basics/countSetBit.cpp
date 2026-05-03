#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Comparator function
    static bool cmp(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        
        // Sort in descending order of set bits
        return countA > countB;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        // Stable sort to maintain original order for equal set bits
        stable_sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.sortBySetBitCount(arr);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}