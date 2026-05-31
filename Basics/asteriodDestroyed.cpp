#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int asteroid : asteroids)
        {
            if (currMass < asteroid)
            {
                return false;
            }

            currMass += asteroid;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};

    if (sol.asteroidsDestroyed(mass, asteroids))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}