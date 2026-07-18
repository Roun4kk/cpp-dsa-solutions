# Find Greatest Common Divisor of Array

**Platform:** LeetCode  
**Difficulty:** Easy  
**Topics:** Math, Array, Number Theory (GCD)

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Code

```cpp
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
```
