#include "minCircle.h"
#include <math.h>
#include <vector>

float DistanceBetweenTwoPoints(Point p1, Point p2) {
    float distance = sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
    return distance;
}
bool IsPointOnCircleBoundaries(Point p, Circle c) {
    float distance = DistanceBetweenTwoPoints(p,c.center);
    if (distance == c.radius)
        return true;
    return false;
}
bool IsPointInCircle(Point p, Circle c) {
    float distance = DistanceBetweenTwoPoints(p,c.center);
    if (distance < c.radius)
        return true;
    return false;
}
bool AreAllPointsInCirlce (Circle c, vector<Point> p) {

    for (int i = 0 ; i<p.size();i++) {
        Point temp = p[i];
        if(IsPointInCircle(p[i],c) == false)
            return false;
        return true;
    }
}
Circle CreateCircleFromTwoPoints (Point p1, Point p2) {
    Point center((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    float r = DistanceBetweenTwoPoints(p1,center);
    return Circle(center,r);
}
Circle CreateCircleFromThreePoints (Point p1, Point p2,Point p3) {

}







