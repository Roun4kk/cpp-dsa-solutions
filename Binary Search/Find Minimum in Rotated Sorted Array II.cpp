// Problem: Find Minimum in Rotated Sorted Array II
// Platform: LeetCode
// Difficulty: Hard
// Topics: Array, Binary Search

// Approach:
// - Store the last element as reference.
// - Skip duplicate elements from the beginning equal to last.
// - Use binary search:
//      * If nums[mid] > last, minimum lies on right side.
//      * Otherwise minimum lies on left side including mid.
// - Return nums[left].

// Time Complexity: O(log n) average, O(n) worst case (due to duplicates)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;

        int last = nums[n];

        int left = 0;
        int right = n;

        while (left < n && nums[left] == last)
            left++;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] > last)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return nums[left];
    }
};
