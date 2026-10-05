#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    // Floating Point:
    float f1 {1.12345678901234567890f};
    double f2 {1.12345678901234567890};
    long double f3 {1.12345678901234567890L};
    cout << setprecision(25);

    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;

    // Scientific Notation
    double d1 {192400023};
    double d2 {1.9240023e8};
    double d3 {1.924e8};
    double d4 {3.498e-11};

    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << d4 << endl;
    
    return 0;
}