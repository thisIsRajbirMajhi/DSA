// I/O
#include <iostream>
#include <stdio.h>
#include <iomanip>

// Data Structures
#include <cstring>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Algorithms
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <cfloat>

// Utilities
#include <utility>
#include <functional>

using namespace std;

// passing string to functions


int main(){
    
    // C Strings (Character Arrays)
    char str1[] = "Hello"; // compiler auto adds '\0' // modifiable
    char str2[10] = "World"; // size 10 but only 6 bytes used
    char str3[] = {'C', '+', '+', '\0'}; // explicit initialization 

    // Memory Layout and Storage:
    // Stack Allocation:
    char str4[50] = "Hello World"; // fixed size, automatic lifetime 
    
    // String literals (read-only memory):
    char *str5 = "Hello"; // points to read-only memory

    // Dynamic allocation (heap):
    char *str6 = (char*)malloc(50 * sizeof(char));
    strcpy(str6, "Hello World");
    free(str6); // must free

    // read string from user
    char name[20];
    printf("Enter name: ");
    scanf("%s", name); // whitespace is avoided
    printf("Your name: %s", name);

    // read full line text
    printf("Enter second name: ");
    fgets(name, sizeof(name), stdin); // read complete string
    printf("Your second name: ");
    puts(name); // display string

    // <string.h> library functions:

    // Input and Displaying:
    // fgets(), puts()

    // Length and Comparision:
    size_t strlen(const char *s); // returns length (exluding '\0')
    int strcmp(const char *s1, const char *s2); // returns 0 if equal <0 or >0
    int strncmp(const char *s1, const char *s2, size_t n); // compare first n chars
    
    // Copying:
    // char *strcpy();
    // char *strncpy();

    // Searching:
    char *strchr(const char *s, int c); // Find first occurances of char
    char *strrchr(const char *s, int c); // Find last occurances of char
    char *strstr(const char *hayStack, const char *needle); // Find substring

    // <string> library functions:
    string n = "Hello";
    n.size();
    n.length();
    n.capacity();
    n.empty();
    n.max_size();

    char c1 = n[0];
    char s2 = n.at(0);
    char &s3 = n.front();
    char &s4 = n.back();

    n.append(" World");

    return 0;
}