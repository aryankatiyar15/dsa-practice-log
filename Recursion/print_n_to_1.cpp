#include <iostream>
using namespace std;

// Function to print numbers from N to 1 recursively
void printNTo1(int n) {
    if (n == 0) return;  // base case: stop when n reaches 0
    cout << n << " ";
    printNTo1(n - 1);  // recursive call with decremented n
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << "Numbers from " << n << " to 1: ";
    printNTo1(n);
    return 0;
}
