/**
===============================================================================
                    C++ RETURN VALUES - COMPLETE REFERENCE
===============================================================================

1. MAIN FUNCTION RETURN VALUES (Exit Status Codes):
   return 0;     - SUCCESS (program executed successfully)
   return 1;     - GENERAL ERROR (catchall for general errors)
   return 2;     - MISUSE (incorrect usage of shell command)
   return 126;   - COMMAND INVOKED CANNOT EXECUTE
   return 127;   - COMMAND NOT FOUND
   return 128;   - INVALID ARGUMENT TO EXIT
   return 130;   - SCRIPT TERMINATED BY CTRL+C
   return 255;   - EXIT STATUS OUT OF RANGE

2. BOOLEAN RETURN VALUES:
   return true;  - Boolean true (1)
   return false; - Boolean false (0)

3. INTEGER RETURN VALUES:
   return -2147483648; - INT_MIN (minimum 32-bit integer)
   return 2147483647;  - INT_MAX (maximum 32-bit integer)
   return 0;          - Zero/success/empty
   return -1;         - Common error indicator
   return 1;          - Success/found/positive result

4. FLOATING POINT RETURN VALUES:
   return 0.0f;       - Float zero
   return 3.14159f;   - Float pi
   return -1.0f;      - Negative float
   return INFINITY;   - Positive infinity
   return -INFINITY;  - Negative infinity
   return NAN;        - Not a Number

5. CHARACTER RETURN VALUES:
   return 'A';        - Character literal
   return '\0';       - Null character (string terminator)
   return '\n';       - Newline character
   return '\t';       - Tab character
   return 65;         - ASCII value for 'A'

6. POINTER RETURN VALUES:
   return nullptr;    - C++11 null pointer
   return NULL;       - Traditional null pointer (0)
   return &variable;  - Address of a variable
   return array;      - Address of first array element

7. STRING RETURN VALUES:
   return "";         - Empty string
   return "Hello";    - String literal
   return string();   - Empty C++ string object
   return string("Hi"); - C++ string with content

8. CONTAINER RETURN VALUES:
   return {};         - Empty container (C++11)
   return {1,2,3};    - Initializer list
   return vector<int>(); - Empty vector
   return vector<int>{1,2,3}; - Vector with elements

9. ENUM RETURN VALUES:
   enum Status {FAIL=0, SUCCESS=1, PENDING=2};
   return FAIL;       - Enum value 0
   return SUCCESS;    - Enum value 1
   return PENDING;    - Enum value 2

10. SPECIAL RETURN VALUES:
    return EXIT_SUCCESS; - Standard success (0)
    return EXIT_FAILURE; - Standard failure (1)
    return EOF;         - End of file (-1)
    return std::nullopt; - Optional with no value (C++17)

11. MATHEMATICAL CONSTANTS:
    return M_PI;       - Pi (3.14159...)
    return M_E;        - Euler's number (2.71828...)
    return HUGE_VAL;   - Large floating point value
    
12. LIMITS AND BOUNDARIES:
    return CHAR_MAX;   - Maximum char value (127)
    return CHAR_MIN;   - Minimum char value (-128)
    return SHRT_MAX;   - Maximum short value (32767)
    return INT_MAX;    - Maximum int value
    return LONG_MAX;   - Maximum long value

===============================================================================
                            PRACTICAL EXAMPLES
===============================================================================
**/

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <climits>
#include <cmath>
#include <cfloat>
using namespace std;

// 1. Main function return values
int main_examples() {
    // These are what main() can return to OS
    // return 0;     // Success
    // return 1;     // General error
    // return 2;     // Misuse
    // return 127;   // Command not found
    // return 255;   // Out of range
    return EXIT_SUCCESS; // Standard success
}

// 2. Boolean return values
bool isPositive(int x) {
    if (x > 0) return true;   // Boolean true
    else return false;        // Boolean false
}

bool isEven(int x) {
    return (x % 2 == 0);     // Expression that evaluates to bool
}

// 3. Integer return values
int divide(int a, int b) {
    if (b == 0) return -1;   // Error indicator
    return a / b;            // Actual result
}

int factorial(int n) {
    if (n <= 1) return 1;    // Base case
    return n * factorial(n-1); // Recursive case
}

int getMaxInt() {
    return INT_MAX;          // Maximum integer value
}

int getMinInt() {
    return INT_MIN;          // Minimum integer value
}

// 4. Floating point return values
float getPi() {
    return 3.14159f;         // Float literal
}

double getE() {
    return 2.71828;          // Double literal
}

float getInfinity() {
    return INFINITY;         // Positive infinity
}

float getNaN() {
    return NAN;              // Not a Number
}

double getHugeValue() {
    return HUGE_VAL;         // Large value
}

// 5. Character return values
char getFirstLetter() {
    return 'A';              // Character literal
}

char getNullChar() {
    return '\0';             // Null terminator
}

char getNewline() {
    return '\n';             // Newline character
}

char getASCII(int code) {
    return (char)code;       // ASCII character
}

// 6. Pointer return values
int* getNullPointer() {
    return nullptr;          // C++11 null pointer
}

int* getArrayPointer() {
    static int arr[] = {1,2,3,4,5};
    return arr;              // Pointer to array
}

int* getVariableAddress(int& x) {
    return &x;               // Address of variable
}

// 7. String return values
string getEmptyString() {
    return "";               // Empty string literal
}

string getGreeting() {
    return "Hello, World!";  // String literal
}

string getDefaultString() {
    return string();         // Empty string object
}

const char* getCString() {
    return "C-style string"; // C-string pointer
}

// 8. Container return values
vector<int> getEmptyVector() {
    return {};               // Empty vector
}

vector<int> getNumbers() {
    return {1, 2, 3, 4, 5}; // Vector with initializer list
}

vector<string> getNames() {
    return vector<string>{"Alice", "Bob", "Charlie"};
}

// 9. Enum return values
enum Status { FAIL = 0, SUCCESS = 1, PENDING = 2 };
enum Priority { LOW = 1, MEDIUM = 5, HIGH = 10 };

Status checkOperation() {
    return SUCCESS;          // Enum value
}

Priority getTaskPriority() {
    return HIGH;             // Enum with custom values
}

// 10. Optional return values (C++17)
optional<int> safeDivide(int a, int b) {
    if (b == 0) return nullopt;  // No value
    return a / b;                // Has value
}

optional<string> findUser(int id) {
    if (id <= 0) return {};      // Empty optional
    return string("User" + to_string(id));
}

// 11. Special mathematical values
double getMathPi() {
    return M_PI;             // Mathematical pi
}

double getEuler() {
    return M_E;              // Euler's number
}

// 12. File operation returns
int readFile() {
    // Simulating file operations
    bool fileExists = false;
    if (!fileExists) return EOF;  // End of file
    return 0;                     // Success
}

// 13. Error code returns
int processData() {
    return EXIT_SUCCESS;     // Standard success
    // return EXIT_FAILURE;  // Standard failure
}

// 14. Limit values
char getMaxChar() {
    return CHAR_MAX;         // 127
}

short getMaxShort() {
    return SHRT_MAX;         // 32767
}

long getMaxLong() {
    return LONG_MAX;         // System dependent
}

// Demo function showing various return values
int main() {
    cout << "=== C++ RETURN VALUES DEMONSTRATION ===" << endl;
    
    // Boolean returns
    cout << "Is 5 positive? " << isPositive(5) << endl;
    cout << "Is 4 even? " << isEven(4) << endl;
    
    // Integer returns
    cout << "10 / 2 = " << divide(10, 2) << endl;
    cout << "10 / 0 = " << divide(10, 0) << " (error code)" << endl;
    cout << "5! = " << factorial(5) << endl;
    cout << "INT_MAX = " << getMaxInt() << endl;
    
    // Float returns
    cout << "Pi = " << getPi() << endl;
    cout << "E = " << getE() << endl;
    cout << "Infinity = " << getInfinity() << endl;
    
    // Character returns
    cout << "First letter: " << getFirstLetter() << endl;
    cout << "ASCII 65: " << getASCII(65) << endl;
    
    // Pointer returns
    int* nullPtr = getNullPointer();
    cout << "Null pointer: " << nullPtr << endl;
    
    int* arrPtr = getArrayPointer();
    cout << "Array first element: " << arrPtr[0] << endl;
    
    // String returns
    cout << "Empty string length: " << getEmptyString().length() << endl;
    cout << "Greeting: " << getGreeting() << endl;
    cout << "C-string: " << getCString() << endl;
    
    // Container returns
    vector<int> nums = getNumbers();
    cout << "Numbers: ";
    for(int n : nums) cout << n << " ";
    cout << endl;
    
    // Enum returns
    Status s = checkOperation();
    cout << "Operation status: " << s << endl;
    
    Priority p = getTaskPriority();
    cout << "Task priority: " << p << endl;
    
    // Optional returns
    auto result = safeDivide(10, 2);
    if (result.has_value()) {
        cout << "Safe division result: " << result.value() << endl;
    }
    
    auto badResult = safeDivide(10, 0);
    if (!badResult.has_value()) {
        cout << "Division by zero handled safely" << endl;
    }
    
    // Mathematical constants
    cout << "Mathematical Pi: " << getMathPi() << endl;
    cout << "Euler's number: " << getEuler() << endl;
    
    // Limit values
    cout << "CHAR_MAX: " << (int)getMaxChar() << endl;
    cout << "SHRT_MAX: " << getMaxShort() << endl;
    
    return EXIT_SUCCESS;  // Standard success return for main
}