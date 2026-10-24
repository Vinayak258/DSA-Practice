
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob)
    {
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        auto convert = [&](string date)
        {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 0; i < month - 1; i++)
            {
                day += days[i];
            }

            return day;
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        return max(0, end - start + 1);
    }
};

int main()
{
    Solution sol;

    string arriveAlice, leaveAlice, arriveBob, leaveBob;

    cout << "Enter Alice's arrival and departure dates: ";
    cin >> arriveAlice >> leaveAlice;

    cout << "Enter Bob's arrival and departure dates: ";
    cin >> arriveBob >> leaveBob;

    int result = sol.countDaysTogether(
        arriveAlice, leaveAlice, arriveBob, leaveBob);

    cout << "Days spent together: " << result << endl;

    return 0;
}
