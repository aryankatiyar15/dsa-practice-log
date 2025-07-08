#include <bits/stdc++.h>
using namespace std;

// insertSorted(): Helper function to insert an element into a sorted array recursively
void insertSorted(vector<int>& arr, int temp) {
    //  Base case: If the array is empty or the last element is less than or equal to temp, insert it directly
    if (arr.empty() || arr.back() <= temp) {
        arr.push_back(temp);
        return;
    }

    //  Otherwise, remove the last element and keep searching where to place temp
    int last = arr.back();
    arr.pop_back();

    insertSorted(arr, temp);  //  Recursive call to keep reducing the array size

    //  Put the removed element back after placing temp in the right place
    arr.push_back(last);
}

//  sortArray(): Recursively sorts the array using insertion sort idea
void sortArray(vector<int>& arr) {
    //  Base case: If array has one or zero elements, it's already sorted
    if (arr.size() <= 1) return;

    //  Step 1: Remove the last element
    int temp = arr.back();
    arr.pop_back();

    //  Step 2: Recursively sort the remaining array
    sortArray(arr);

    // Step 3: Insert the removed element back into the correct position
    insertSorted(arr, temp);
}

int main() {
    //  Test array
    vector<int> arr = {5, 1, 0, 2, 8};

    //  Sort the array
    sortArray(arr);

    //  Print the sorted result
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
