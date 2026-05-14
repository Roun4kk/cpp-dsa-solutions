// Problem: Two Sum
// Platform: LeetCode
// Difficulty: Easy
// Topic: Array, Two Pointers, Sorting

// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:

    int find(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == target) {
                nums[i] = -1;
                return i;
            }
        }

        return 0;
    }

    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> copy = nums;

        sort(nums.begin(), nums.end());

        int a = 0;
        int b = nums.size() - 1;

        while (b > a) {

            int sum = nums[a] + nums[b];

            if (sum > target) {
                b--;
            }

            if (sum < target) {
                a++;
            }

            if (sum == target) {
                return {
                    find(copy, nums[a]),
                    find(copy, nums[b])
                };
            }
        }

        return {};
    }
};
