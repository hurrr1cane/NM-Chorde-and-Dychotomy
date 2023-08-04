#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Header.h"

using namespace std;

int main(void) {
    int count = 0, check = 0;
    double a = 1, b = -4, c = -9, d = 2, x, eps = 0.000001,
    l = 4, r = 8;

    cout << '\n';

    count = 0;
    do {
        cout << "\nEnter a, b, eps: ";
        cin >> l >> r >> eps;
        cout << "\n";
        check = checker(a, b, c, d, l, r);
    } while (check == 0);

    x = DychotomyMethod(a, b, c, d, l, r, eps, &count);
    cout << "Func " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\nA = " << l << " B = " << r << " Eps = " << eps <<"\n";
    cout << "Dychotomy: x = " << x << " Iterations: " << count << '\n';
    x = ChordeMethod(a, b, c, d, l, r, eps, &count);
    cout << "Chorde: x = " << x << " Iterations: " << count << "\n\n";

    //l = -10; r = -1.5;

    do {
        cout << "\nEnter a, b, eps: ";
        cin >> l >> r >> eps;
        cout << "\n";
        check = checker(a, b, c, d, l, r);
    } while (check == 0);
    x = DychotomyMethod(a, b, c, d, l, r, eps, &count);
    cout << "Func " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\nA = " << l << " B = " << r << " Eps = " << eps << "\n";
    cout << "Dychotomy: x = " << x << " Iterations: " << count << '\n';
    x = ChordeMethod(a, b, c, d, l, r, eps, &count);
    cout << "Chorde: x = " << x << " Iterations: " << count << "\n\n";

    //l = 0; r = 1;

    do {
        cout << "\nEnter a, b, eps: ";
        cin >> l >> r >> eps;
        cout << "\n";
        check = checker(a, b, c, d, l, r);
    } while (check == 0);
    x = DychotomyMethod(a, b, c, d, l, r, eps, &count);
    cout << "Func " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\nA = " << l << " B = " << r << " Eps = " << eps << "\n";
    cout << "Dychotomy: x = " << x << " Iterations: " << count << '\n';
    x = ChordeMethod(a, b, c, d, l, r, eps, &count);
    cout << "Chorde: x = " << x << " Iterations: " << count << "\n\n";
}