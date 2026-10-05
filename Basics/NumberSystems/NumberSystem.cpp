#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

    // Decimal:     Base: 10 --> 0-9 
    // Binary:      Base: 2  --> 0-1
    // Octal:       Base: 8  --> 0-7
    // Hexadecimal: Base: 16 --> 0-9, A-F

    //? Decimal
    // 5 × 10² + 7 × 10¹ + 2 × 10⁰
    // = 500 + 70 + 2
    // = 572

    int num1 = 15; // Decimal
    int num2 = 017; // Octal
    int num3 = 0x0F; // hexadecimal
    int num4 = 0b00001111; // Binary

    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << num4 << endl;
   
    // Integers: 4 Bytes or more

    // Variable braced initialization
    
    // Variable may contain random garbage value
    int count;

    int count_one{};         // Initializes to 0
    int count_two{10};      // Initializes to 10
    int count_three{15};   // Initializes to 15
    int count_four{count_two + count_three}; // can use expression as initializer
    

    printf("%d");   // decimal
    printf("%o");   // octal
    printf("%x");   // hexadecimal lowercase
    printf("%X");   // hexadecimal uppercase

    printf("%d", sizeof(num1));

    return 0;
}