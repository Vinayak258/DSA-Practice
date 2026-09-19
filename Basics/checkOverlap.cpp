#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2)
    {

        // Find the closest point of the rectangle
        // to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Difference between center and closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Check if distance <= radius
        return dx * dx + dy * dy <= radius * radius;
    }
};

int main()
{
    int radius, xCenter, yCenter;
    int x1, y1, x2, y2;

    cin >> radius >> xCenter >> yCenter;
    cin >> x1 >> y1 >> x2 >> y2;

    Solution obj;

    bool ans = obj.checkOverlap(
        radius,
        xCenter,
        yCenter,
        x1, y1,
        x2, y2);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}