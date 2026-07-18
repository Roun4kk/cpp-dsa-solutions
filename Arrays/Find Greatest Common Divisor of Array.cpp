// LeetCode
// Find Greatest Common Divisor of Array
// Difficulty: Easy
// Topics: Math, Array, Number Theory (GCD)

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int gcd(int a, int b) {
        if (b > a) return gcd(b, a);
        if (!(a % b)) return b;
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        return gcd(l, r);
    }
};
