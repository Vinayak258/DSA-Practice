#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int pour(int fromCap, int toCap, int d) {
        int from = fromCap; // fill source jug
        int to = 0;         // destination jug
        
        int steps = 1; // first fill

        while (from != d && to != d) {
            int transfer = min(from, toCap - to);

            to += transfer;
            from -= transfer;
            steps++; // pouring step

            if (from == d || to == d)
                break;

            if (from == 0) {
                from = fromCap;
                steps++; // refill source
            }

            if (to == toCap) {
                to = 0;
                steps++; // empty destination
            }
        }

        return steps;
    }

    int minSteps(int m, int n, int d) {
        if (d > max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;

        return min(pour(m, n, d), pour(n, m, d));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of test cases

    while (t--) {
        int m, n, d;
        cin >> m >> n >> d;

        Solution obj;
        cout << obj.minSteps(m, n, d) << "\n";
    }

    return 0;
}