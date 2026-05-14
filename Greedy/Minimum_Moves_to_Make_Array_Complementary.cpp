// Problem: Minimum Moves to Make Array Complementary
// Platform: LeetCode
// Difficulty: Medium
// Topic: Difference Array, Prefix Sum, Greedy

// Time Complexity: O(n + limit)
// Space Complexity: O(limit)

// Key Insight:
// For every mirrored pair (a,b):
// - 0 moves needed for target = a+b
// - 1 move needed for targets in range [a+1, b+limit]
// - 2 moves needed outside that range
//
// Use a difference array to efficiently apply
// range-based move contributions for all targets.

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff((limit + 1) * 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            if (a > b)
                swap(a, b);

            // Initially assume 2 moves for all targets
            diff[2] += 2;

            // Targets from [a+1, ...] need 1 less move
            diff[a + 1]--;

            // Target = a+b needs another 1 less move (0 moves)
            diff[a + b]--;

            // After a+b, back to 1 move
            diff[a + b + 1]++;

            // After b+limit, back to 2 moves
            diff[b + limit + 1]++;
        }

        int moves = 0;
        int ans = INT_MAX;

        for (int target = 2; target <= 2 * limit; target++) {
            moves += diff[target];
            ans = min(ans, moves);
        }

        return ans;
    }
};
