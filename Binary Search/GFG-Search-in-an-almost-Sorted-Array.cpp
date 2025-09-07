/*
 Problem: Search in Nearly Sorted Array

🔹 Logic:
In a nearly sorted array, each element may be at index `i`, `i-1`, or `i+1`.  
We need to search efficiently using a modified binary search.

1. Standard binary search loop: low to high.
2. Compute mid = low + (high - low)/2.
3. Check if arr[mid], arr[mid-1], or arr[mid+1] is the target (with boundary checks).
4. If target > arr[mid], search right but skip two elements (low = mid+2).
5. Else search left but skip two elements (high = mid-2).
6. Return -1 if target not found.

Example:  
Input: arr = [5, 10, 30, 20, 40], target = 20  
Output: 3  

Time Complexity: O(log n) – still binary search, just with extra checks.  

Space Complexity: O(1) – only variables used.
*/

class Solution {
public:
    int findTarget(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target)
                return mid;
            
            if (mid - 1 >= low && arr[mid - 1] == target)
                return mid - 1;
            
            if (mid + 1 <= high && arr[mid + 1] == target)
                return mid + 1;

            if (arr[mid] < target)
                low = mid + 2;  
            else
                high = mid - 2; 
        }
        return -1;
    }
};
