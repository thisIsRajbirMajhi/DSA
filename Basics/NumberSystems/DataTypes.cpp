#include <stdio.h>
#include <iostream>
using namespace std;

// Integer:  char, short, int, long / long long
// Floating: float, double, long double
// Boolean:  bool
// void

int main(){

    cout << "Int: " << sizeof(int) << endl;
    cout << "Char: " << sizeof(char) << endl;
    cout << "Short: " << sizeof(short) << endl;
    cout << "Long: " << sizeof(long) << endl;
    cout << "Long Long: " << sizeof(long long) << endl;
    cout << "Float: " << sizeof(float) << endl;
    cout << "Double: " << sizeof(double) << endl;
    cout << "Long Double " << sizeof(long double) << endl;
    cout << "Bool: " << sizeof(bool) << endl;

    // Signed: Can represent negative and positive values.
    int x = -10;
    int y = 10;

    // Unsigned: Cannot represent negative values, but provides a larger non-negative range for a given width.
    unsigned int z = 100;

    cout << sizeof(y) << endl;
    cout << sizeof(z) << endl;

    signed int val1 {10};
    signed int val2 {-130}; 

    short short_var {-32768} ; // 2 Bytes
    short int short_int {455} ; //
    signed short signed_short {122}; //
    signed short int signed_short_int {-456}; //
    unsigned short int unsigned_short_int {456};

    int int_var {55} ; // 4 bytes
    signed signed_var {66};//
    signed int signed_int {77};//
    unsigned int unsigned_int{77};

    long long_var {88}; // 4 OR 8 Bytes
    long int long_int {33};
    signed long signed_long {44};
    signed long int signed_long_int {44};
    unsigned long int unsigned_long_int{44};

    long long long_long {888};// 8 Bytes
    long long int long_long_int {999};
    signed long long signed_long_long {444};
    signed long long int signed_long_long_int{1234};
    unsigned long long int unsigned_long_long_int{1234};
    
    // Floating Point:
    float f1 {1.12345678901234567890f};
    double f2 {1.12345678901234567890};
    long double f3 {1.12345678901234567890L};

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