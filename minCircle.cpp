#include "minCircle.h"
#include <math.h>

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





