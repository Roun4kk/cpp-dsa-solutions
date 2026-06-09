// Problem: Maximum Total Subarray Value I
// Platform: LeetCode
// Difficulty: Medium
// Topics: Array, Greedy

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return (long long)((long long)*max_element(nums.begin(), nums.end()) -
                           (long long)*min_element(nums.begin(), nums.end())) *
               (long long)k;
    }
};
