/**
===============================================================================
                    C++ FUNCTION RETURN TYPES - COMPLETE CHEAT SHEET
===============================================================================

1. BASIC DATA TYPES:
   int func()     - Returns integer (-2³¹ to 2³¹-1)
   float func()   - Returns single precision decimal (4 bytes)
   double func()  - Returns double precision decimal (8 bytes)
   char func()    - Returns single character (1 byte)
   bool func()    - Returns true/false (1 byte)
   short func()   - Returns short integer (2 bytes)
   long func()    - Returns long integer (4/8 bytes)

2. VOID RETURN:
   void func()    - Returns nothing (no return statement needed)

3. POINTER RETURNS:
   int* func()    - Returns address/pointer to integer
   char* func()   - Returns pointer to character/string
   void* func()   - Returns generic pointer (any type)

4. REFERENCE RETURNS:
   int& func()    - Returns reference to integer (alias)
   const int& func() - Returns read-only reference

5. ARRAY RETURNS:
   int* func()    - Returns pointer to first element (array decay)
   int (&func())[5] - Returns reference to array of 5 integers

6. STRING RETURNS:
   string func()  - Returns C++ string object
   char* func()   - Returns C-style string (char array)
   const char* func() - Returns read-only C-style string

7. CLASS/STRUCT RETURNS:
   MyClass func() - Returns object by value (copy)
   MyClass& func() - Returns object by reference
   MyClass* func() - Returns pointer to object

8. CONTAINER RETURNS:
   vector<int> func()    - Returns vector container
   list<string> func()   - Returns list container
   map<int,string> func() - Returns map container

9. FUNCTION POINTER RETURNS:
   int (*func())(int)    - Returns pointer to function
   function<int(int)> func() - Returns function object

10. AUTO RETURN (C++11+):
    auto func()           - Compiler deduces return type
    auto func() -> int    - Trailing return type syntax

11. TEMPLATE RETURNS:
    template<typename T>
    T func()              - Returns template type T

12. ENUM RETURNS:
    enum Color {RED, GREEN, BLUE};
    Color func()          - Returns enumeration value

13. OPTIONAL RETURNS (C++17+):
    optional<int> func()  - Returns value or nothing
    
14. VARIANT RETURNS (C++17+):
    variant<int,string> func() - Returns one of multiple types

===============================================================================
                                USAGE EXAMPLES
===============================================================================
**/

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <variant>
using namespace std;

// 1. Basic Data Types
int getAge() { return 25; }
float getHeight() { return 5.8f; }
double getPi() { return 3.14159; }
char getGrade() { return 'A'; }
bool isAdult() { return true; }

// 2. Void Return
void printMessage() { 
    cout << "Hello!"; 
    // No return statement needed
}

// 3. Pointer Returns
int* getNumbers() {
    static int arr[] = {1, 2, 3, 4, 5};
    return arr;  // Returns address of first element
}

char* getName() {
    return "John Doe";  // Returns pointer to string literal
}

// 4. Reference Returns
int& getReference(int& x) {
    return x;  // Returns reference to parameter
}

const int& getConstRef() {
    static int value = 100;
    return value;  // Returns read-only reference
}

// 5. String Returns
string getFullName() {
    return "John Smith";  // Returns C++ string object
}

const char* getCStyleString() {
    return "Hello World";  // Returns C-style string
}

// 6. Class/Struct Returns
struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

Point getOrigin() {
    return Point(0, 0);  // Returns Point object by value
}

Point& getStaticPoint() {
    static Point p(10, 20);
    return p;  // Returns reference to static Point
}

// 7. Container Returns
vector<int> getEvenNumbers() {
    return {2, 4, 6, 8, 10};  // Returns vector
}

// 8. Function Pointer Returns
int add(int a, int b) { return a + b; }

int (*getOperation())(int, int) {
    return add;  // Returns pointer to add function
}

// 9. Auto Return (C++11+)
auto getDouble(int x) {
    return x * 2.0;  // Compiler deduces return type as double
}

auto getString() -> string {
    return "Auto with trailing return type";
}

// 10. Template Returns
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;  // Returns type T
}

// 11. Enum Returns
enum Status { SUCCESS, ERROR, PENDING };

Status checkConnection() {
    return SUCCESS;  // Returns enum value
}

// 12. Optional Returns (C++17+)
optional<int> divide(int a, int b) {
    if (b == 0) return nullopt;  // Return nothing
    return a / b;  // Return value
}

// 13. Variant Returns (C++17+)
variant<int, string> processData(bool useNumber) {
    if (useNumber) 
        return 42;           // Return int
    else 
        return string("Hello"); // Return string
}

// Main function demonstrating all return types
int main() {
    // Basic types
    cout << "Age: " << getAge() << endl;
    cout << "Height: " << getHeight() << endl;
    cout << "Pi: " << getPi() << endl;
    cout << "Grade: " << getGrade() << endl;
    cout << "Is Adult: " << isAdult() << endl;
    
    // Void function
    printMessage();
    cout << endl;
    
    // Pointer returns
    int* numbers = getNumbers();
    cout << "First number: " << numbers[0] << endl;
    
    char* name = getName();
    cout << "Name: " << name << endl;
    
    // Reference returns
    int value = 50;
    int& refValue = getReference(value);
    refValue = 100;  // Modifies original value
    cout << "Modified value: " << value << endl;
    
    // String returns
    string fullName = getFullName();
    cout << "Full Name: " << fullName << endl;
    
    // Class returns
    Point origin = getOrigin();
    cout << "Origin: (" << origin.x << ", " << origin.y << ")" << endl;
    
    // Container returns
    vector<int> evens = getEvenNumbers();
    cout << "Even numbers: ";
    for(int n : evens) cout << n << " ";
    cout << endl;
    
    // Function pointer returns
    auto operation = getOperation();
    cout << "5 + 3 = " << operation(5, 3) << endl;
    
    // Auto returns
    auto result = getDouble(5);
    cout << "Double of 5: " << result << endl;
    
    // Template returns
    cout << "Max of 10 and 20: " << getMax(10, 20) << endl;
    cout << "Max of 'a' and 'z': " << getMax('a', 'z') << endl;
    
    // Enum returns
    Status status = checkConnection();
    cout << "Connection status: " << status << endl;
    
    // Optional returns
    auto divResult = divide(10, 2);
    if (divResult.has_value()) {
        cout << "Division result: " << divResult.value() << endl;
    }
    
    auto badDiv = divide(10, 0);
    if (!badDiv.has_value()) {
        cout << "Division by zero detected!" << endl;
    }
    
    // Variant returns
    auto data1 = processData(true);   // Returns int
    auto data2 = processData(false);  // Returns string
    
    return 0;  // Standard success return
}