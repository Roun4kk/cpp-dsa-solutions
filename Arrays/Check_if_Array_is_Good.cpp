// Problem: Check if Array is Good
// Platform: LeetCode
// Difficulty: Easy
// Topic: Array, Frequency Count

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n + 1);

        for (int x : nums) {
            if (x > n - 1)
                return false;

            freq[x]++;
        }

        for (int i = 1; i < n - 1; i++) {
            if (freq[i] != 1)
                return false;
        }

        return freq[n - 1] == 2;
    }
};
