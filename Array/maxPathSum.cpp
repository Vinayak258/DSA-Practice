#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPathSum(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    int ans = 0;

    while (i < a.size() && j < b.size()) {

        if (a[i] < b[j]) {
            sum1 += a[i];
            i++;
        }
        else if (a[i] > b[j]) {
            sum2 += b[j];
            j++;
        }
        else {
            // Common element
            ans += max(sum1, sum2) + a[i];

            sum1 = 0;
            sum2 = 0;

            i++;
            j++;
        }
    }

    // Add remaining elements
    while (i < a.size()) {
        sum1 += a[i];
        i++;
    }

    while (j < b.size()) {
        sum2 += b[j];
        j++;
    }

    ans += max(sum1, sum2);

    return ans;
}

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << "Maximum Path Sum = " << maxPathSum(a, b) << endl;

    return 0;
}