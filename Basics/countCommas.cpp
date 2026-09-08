#include <iostream>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        return n - 999;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << obj.countCommas(n) << endl;

    return 0;
}