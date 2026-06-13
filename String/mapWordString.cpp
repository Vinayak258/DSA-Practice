#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans;

        for (string &word : words)
        {
            long long sum = 0;

            for (char ch : word)
            {
                sum += weights[ch - 'a'];
            }

            ans.push_back('z' - (sum % 26));
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    vector<int> weights(26);

    cout << "Enter 26 weights:\n";
    for (int i = 0; i < 26; i++)
    {
        cin >> weights[i];
    }

    Solution obj;
    string result = obj.mapWordWeights(words, weights);

    cout << "Output: " << result << endl;

    return 0;
}