#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // Closing brackets
            else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        // If stack is empty, all brackets were matched
        return st.empty();
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    if (obj.isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}