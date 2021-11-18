#include "minCircle.h"
#include <math.h>
#include <vector>
#include "anomaly_detection_util.h"
#include <limits>
#include <random>
#include <algorithm>

float CalculateSlope (Point p1, Point p2) {
    float slope;
    if (p1.x==p2.x)
        slope = std::numeric_limits<float>::infinity();
    slope = (p2.y-p1.y)/(p2.x-p1.x);
    return slope;

}
Line CreateLineFromTwoPoints(Point p1, Point p2) {
    float slope = CalculateSlope(p1,p2);
    float b = p1.y - slope*p1.x;
    Line l(slope,b);
    return l;
}
Point IntersectionPointOfTwoLines(Line l1, Line l2) {
//    mx+n = ax+b
//            mx - ax = b -n
//                    x(m-a) = b-n
//                            x = (b-n)/(m-a)
    float x = (l2.b-l1.b)/(l1.a-l2.a);
    float y = l1.a*x+l1.b;
    return Point(x,y);
}
Line CreateLineFromPointAndSlope(Point p, float slope) {
    float b = p.y-slope*p.x;
    return Line(slope,b);
    //y = mx+b
    //b= y-mx
}


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
bool AreAllPointsInCircle (Circle c, vector<Point*> p) {
    for (int i = 0 ; i<p.size();i++) {
        Point temp = *p[i];
        if(IsPointInCircle(temp,c) == false)
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
    Line l1 = CreateLineFromTwoPoints(p1,p2);
    Line l2 = CreateLineFromTwoPoints(p2,p3);
    Point midL1((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    Point midL2((p2.x+p3.x)/2,(p2.y+p3.y)/2);
    Line L1P = CreateLineFromPointAndSlope(midL1,-1/l1.a);
    Line L2P = CreateLineFromPointAndSlope(midL2,-1/l2.a);
    Point center = IntersectionPointOfTwoLines(L1P,L2P);
    float radius = DistanceBetweenTwoPoints(center,p1);
    return Circle(center,radius);
}
Circle findMinCircleHelpAlgorithm(vector<Point*> p, vector<Point*> r) {
    vector<Point*> copy = p;
    if (p.size() == 0 || r.size() == 3) {
        if (r.size() == 0) {
            return Circle(Point(0, 0), 0);
        }
        if (r.size() == 1) {
            return Circle(*r[0], 0);
        }
        if (r.size() == 2) {
            return CreateCircleFromTwoPoints(*r[0], *r[1]);
        }
        if (r.size() == 3) {
            Circle c = CreateCircleFromTwoPoints(*r[0], *r[1]);
            if (AreAllPointsInCircle(c, copy) == true)
                return c;
            c = CreateCircleFromTwoPoints(*r[0], *r[2]);
            if (AreAllPointsInCircle(c, copy) == true)
                return c;
            c = CreateCircleFromTwoPoints(*r[1], *r[2]);
            if (AreAllPointsInCircle(c, copy) == true)
                return c;
            c = CreateCircleFromThreePoints(*r[0], *r[1], *r[2]);
            return c;
        }
        std::shuffle(p.begin(), p.end(), std::random_device());
        Point *point = p[p.size() - 1];
        p.pop_back();
        Circle d = findMinCircleHelpAlgorithm(p, r);
        if (IsPointInCircle(*point, d)) {
            return d;
        } else {
            r.push_back(point);
            return findMinCircleHelpAlgorithm(p, r);
        }
    }
}

Circle findMinCircle(Point** points,size_t size) {
    vector<Point*> p;
    for(int i = 0;i<size;i++) {
        p.push_back(points[i]);
    }
    vector<Point*> r;
    return findMinCircleHelpAlgorithm(p,r);
}











