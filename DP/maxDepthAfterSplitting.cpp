#include <bits/stdc++.h>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans;
    int depth = 0;

    for (char c : seq) {

        if (c == '(') {
            depth++;
            ans.push_back(depth % 2);
        }
        else {
            ans.push_back(depth % 2);
            depth--;
        }
    }

    return ans;
}

int main() {

    string seq;

    cout << "Enter parentheses string: ";
    cin >> seq;

    vector<int> ans = maxDepthAfterSplit(seq);

    cout << "Answer: [";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1)
            cout << ",";
    }

    cout << "]" << endl;

    return 0;
}