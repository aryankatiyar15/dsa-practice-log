/*
Problem: Find First and Last Position of Element in Sorted Array (LeetCode 34)

Logic:
We need to find the first and last occurrence of a target element in a sorted array.

1. Use a modified binary search to find the first occurrence:
   - When arr[mid] == target, update answer = mid and move left (high = mid-1).
2. Use a modified binary search to find the last occurrence:
   - When arr[mid] == target, update answer = mid and move right (low = mid+1).
3. If the target is not found in the first search, return {-1, -1}.
4. Otherwise, return {first, last}.

Example:  
Input: nums = [5,7,7,8,8,10], target = 8  
Output: [3,4]  

Time Complexity: O(log n) – binary search twice.  

Space Complexity: O(1) – constant extra space.
*/

class Solution {
public:
    int first_occurence(vector<int> &arr, int x) {
        int n = arr.size(), low = 0, high = n-1, mid = 0, first = -1;
        while(low <= high) {
            mid = (low+high)/2;
            if(arr[mid] == x) {
                first = mid;
                high = mid-1; // move left
            }
            else if(arr[mid] > x) {
                high = mid-1;
            }
            else low = mid+1;
        }
        return first;
    }

    int last_occurence(vector<int> &arr, int x) {
        int n = arr.size(), low = 0, high = n-1, mid = 0, last = -1;
        while(low <= high) {
            mid = (low+high)/2;
            if(arr[mid] == x) {
                last = mid;
                low = mid+1; // move right
            }
            else if(arr[mid] > x) {
                high = mid-1;
            }
            else low = mid+1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_occurence(nums, target);
        if(first == -1) return {-1, -1};
        int last = last_occurence(nums, target);
        return {first, last};
    }
};
