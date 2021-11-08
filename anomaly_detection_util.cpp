//
// Uri Greitser 209289891 and Omri Ben Hemo 313255242
//

#include "anomaly_detection_util.h"
#include <cmath>


// returns the variance of X and Y
float var(float *x, int size) {
    float u = 0;
    float ans;
    float temp = 0;
    //calculates the u value -  average
    for (int i=0;i<size;i++) {
        u += x[i];
    }
    u /= size;
    //calculates the formula using the u
    for (int i =0;i<size;i++) {
        temp+=(x[i]*x[i]);
    }
    temp /= size;
    ans = temp - (u*u);
    return ans;

}

//returns the average of the array.
float average(float* x, int size) {
    float sum = 0;
    for (int i = 0; i < size;i++){
        sum += x[i];
    }
    sum = sum/size;
    return sum;
}
//subtraction average from each element in the array.
float* sub(float* x, float ave, int size){
    for(int i = 0; i < size; i++){
        x[i] = x[i] - ave;
    }
    return x;
}
//multiply two arrays.
float averageOfTwoArrays(float* x, float* y, int size){
    float tempArr[size];
    for(int i = 0; i < size; i++){
        tempArr[i] = x[i]*y[i];
    }
    return average(tempArr,size);
}
// returns the covariance of X and Y
float cov(float* x, float* y, int size) {
    //𝐸(𝑋𝑌) − 𝐸(𝑋)𝐸(𝑌)
    float ex = average(x,size);
    float ey = average(y,size);
    float twoArrays = averageOfTwoArrays(x,y,size);
    float answer = twoArrays - ex*ey;
    return answer;
}
// returns the Pearson correlation coefficient of X and Y
float pearson(float *x, float *y, int size){
    //𝑐𝑜𝑣(𝑋, 𝑌)/square root of 𝜎x𝜎y
    float temp1 = cov(x,y,size);
    float temp2 = sqrt(var(x,size)) * sqrt(var(y,size));
    return temp1/temp2;
}


// performs a linear regression and return s the line equation
Line linear_reg(Point **points, int size) {
    float xArray[size];
    float yArray[size];
    //separate the x and the y of the points, each one to new array.
    for(int i=0;i<size;i++){
        xArray[i] = points[i]->x;
        yArray[i] = points[i]->y;
    }
    float *xPtr = xArray;
    float *yPtr = yArray;
    //linear regression formula: b = average of 𝑦 - (𝐶𝑂𝑉(𝑥,𝑦)/𝑉𝐴𝑅(𝑥))(average of 𝑥)
    float a = cov(xPtr,yPtr,size)/ var(xPtr,size);
    float b = average(yPtr,size)- a* average(xPtr,size);
    Line l =  Line(a,b);
    return l;
}
// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size){
    Line l = linear_reg(points,size);
    return dev(p,l);
}
// returns the deviation between point p and the line
float dev(Point p,Line l) {
    float temp = l.a*p.x + l.b;
    if (temp > p.y)
        return temp - p.y;
    else
        return p.y - temp;
}
