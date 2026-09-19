// LeetCode 1401 : Circle and Rectangle Overlapping
// Problem Link  : https://leetcode.com/problems/circle-and-rectangle-overlapping/

/*
  Intuition:
    Find the point on/in the rectangle that is closest to the center of the circle.
    Let this point be (nearestX, nearestY).

    If the distance from (nearestX, nearestY) to the circle's center (xCenter, yCenter) is greater than the radius,
    then every point of the rectangle lies outside the circle, so no overlap is possible.

    The distance is:
      sqrt((nearestX - xCenter)^2 + (nearestY - yCenter)^2)
    Squaring both sides:
      (nearestX - xCenter)^2 + (nearestY - yCenter)^2

    Therefore, the circle and rectangle overlap iff (nearestX - xCenter)^2 + (nearestY - yCenter)^2 <= radius^2
*/

// Approach 1
// T.C : O(1)
// S.C : O(1)
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX;
        int nearestY;

        if(x1 > xCenter)      nearestX = x1;
        else if(x2 < xCenter) nearestX = x2;
        else                  nearestX = xCenter;

        if(y1 > yCenter)      nearestY = y1;
        else if(y2 < yCenter) nearestY = y2;
        else                  nearestY = yCenter;

        int dSquared = (nearestX-xCenter)*(nearestX-xCenter) + (nearestY-yCenter)*(nearestY-yCenter);
        
        return dSquared <= radius*radius;
    }
};

// Approach 2 (using STL)
// T.C : O(1)
// S.C : O(1)
class Solution {
public:  
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = clamp(xCenter, x1, x2);
        int nearestY = clamp(yCenter, y1, y2);

        return (nearestX-xCenter)*(nearestX-xCenter) + (nearestY-yCenter)*(nearestY-yCenter) <= radius*radius;
    }
};
