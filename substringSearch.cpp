#include <iostream>

using namespace std;

//This is a substringSearch function which checks is U string present in the S string or not.
// if it's present then returns the first index of the U string. if it's not present then return
//the -1
int substringSearch(const string &S, const string &U) {
    int m = S.length();  // length of the S string
    int n = U.length();  // length of the U string

    // First looping through the S string
    for (int i = 0; i < m - n; i++) {
        int j = 0;

        // if chars matching then looping inside the U string
        while (j < n && S[i + j] == U[j]) {
            j++;
        }
        // checking U string length is equal to the jth index
        if (j == n) {
            return i;     // return the ith index
        }
    }
    return -1;      // string not found
}

int main() {

    struct Test {
        string s;
        string u;
        int output;
    };

    // Array containing test cases
    Test tests[]{
            {"Happy happy joy joy ", "happy",   6},
            {"Where is the dog?",    "cat",     -1},
            {"fun fun fun",          "fun",     0},
            {"I love coding!",       "Me too!", -1},
    };

    int i = 1;
    for (const Test &test: tests) {
        int result = substringSearch(test.s, test.u);
        cout << "Test Case " << i << ". " << "\n" ;
        cout << "s: " << test.s << " u: " << test.u << "\n";
        cout << "Expected: " << test.output << " Output: " << result << "\n";
        cout << "Result: " << (test.output == result ? "PASSED" : "FAILED") << "\n";
        cout << "-------------------------------" << "\n";
        i++;
    }

    return 0;
}
