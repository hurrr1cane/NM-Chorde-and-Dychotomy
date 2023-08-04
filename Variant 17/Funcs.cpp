#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;

double CubicEquation(double a, double b, double c, double d, double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double poh1(double a, double b, double c, double x) {
    return 3 * a * x * x + 2 * b * x + c;
}

double poh2(double a, double b, double x) {
    return 6 * a * x + 2 * b;
}

double ChordeMethod(double a, double b, double c, double d, double l, double r, double eps, int* count) {

    int variant;
    (*count) = 0;

    if (poh1(a, b, c, (l + r) / 2) * poh2(a, b, (l + r) / 2) > 0) {
        variant = 1;
    }
    else  {
        variant = 0;
    }
    


    double diff = fabs(r - l);
    double x = r;

    switch (variant) {
    case 1:
        while (diff > eps) {
            x = l - ((CubicEquation(a, b, c, d, l)) * (r - l)) / (CubicEquation(a, b, c, d, r) - CubicEquation(a, b, c, d, l));
            diff = fabs(x - l);
            l = x;
            (*count)++;
            if (fabs(CubicEquation(a, b, c, d, x)) < eps) {
                return x;
            }
        }
        break;
    case 0:
        while (diff > eps) {
            x = r - ((CubicEquation(a, b, c, d, r)) * (r - l)) / (CubicEquation(a, b, c, d, r) - CubicEquation(a, b, c, d, l));
            diff = fabs(r - x);
            r = x;
            (*count)++;
            if (fabs(CubicEquation(a, b, c, d, x)) < eps) {
                return x;
            }
        }
        break;
    }

    return x;
}

double DychotomyMethod(double a, double b, double c, double d, double l, double r, double eps, int* count) {
    
    *count = 0;

    double middle, x, length;
    length = r - l;
    x = (r+l)/2;

    while (length > eps) {
        middle = (l + r) / 2;
        if (CubicEquation(a,b,c,d,middle) * CubicEquation(a, b, c, d, l) < 0) {
            length /= 2;
            r = middle;
            x = middle;
        }
        else {
            length /= 2;
            l = middle;
            x = middle;
        }
        (*count)++;
        if (fabs(CubicEquation(a, b, c, d, x)) < eps) {
            return x;
        }
    }
    return x;
}

int checker(double a, double b, double c, double d, double l, double r) {
    if (CubicEquation(a, b, c, d, l) * CubicEquation(a, b, c, d, r) < 0) {
        return 1;
    }
    else {
        cout << "Your interval doesn't have a root!\n";
        return 0;
    }
}