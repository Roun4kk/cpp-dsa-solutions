// Problem: Left and Right Sum Differences
// Platform: LeetCode
// Difficulty: Easy
// Topics: Array, Prefix Sum

// Approach:
// - Traverse from both ends simultaneously.
// - Maintain running left and right sums.
// - Store left sum contribution and subtract right sum contribution.
// - Take absolute value of each position at the end.

// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output array)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int l = 0, r = n - 1;
        int leftSum = 0, rightSum = 0;

        while (l < n && r >= 0) {
            ans[l] += leftSum;
            ans[r] -= rightSum;

            leftSum += nums[l];
            rightSum += nums[r];

            l++;
            r--;
        }

        for (auto& it : ans) {
            it = abs(it);
        }

        return ans;
    }
};
