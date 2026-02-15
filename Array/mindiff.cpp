#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myMin(int a, int b){
        if(a < b) return a;
        return b;
    }

    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = INT_MAX;

        for(int i = 0; i <= n - m; i++){
            int diff = a[i + m - 1] - a[i];
            ans = myMin(ans, diff);
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n;            // number of elements
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];     // array elements

    cin >> m;            // number of students / subset size

    Solution obj;
    cout << obj.findMinDiff(a, m) << endl;

    return 0;
}
