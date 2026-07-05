#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCharGap(string &s) {
        vector<int> first(26, -1);
        int ans = -1;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (first[idx] == -1) {
                first[idx] = i;
            } else {
                ans = max(ans, i - first[idx] - 1);
            }
        }

        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.maxCharGap(s) << endl;

    return 0;
}