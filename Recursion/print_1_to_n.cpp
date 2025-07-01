#include <iostream>
using namespace std;

// Function to print numbers from 1 to N recursively
void print1ToN(int n, int current = 1) {
    if (current > n) return;  // base case: stop when current exceeds n
    cout << current << " ";
    print1ToN(n, current + 1);  // recursive call with incremented current
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << "Numbers from 1 to " << n << ": ";
    print1ToN(n);
    return 0;
}
