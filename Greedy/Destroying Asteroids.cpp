// Problem: Destroying Asteroids
// Platform: LeetCode
// Difficulty: Medium
// Topics: Greedy, Sorting

// Approach:
// - Sort the asteroids in ascending order.
// - Always destroy the smallest asteroid first since it is easiest
//   to absorb and increases our mass for future asteroids.
// - If at any point current mass is smaller than an asteroid,
//   it cannot be destroyed, so return false.
// - Otherwise, absorb the asteroid and increase current mass.
// - Use long long to avoid overflow while accumulating mass.

// Time Complexity: O(n log n)
// Space Complexity: O(1) (excluding sorting space)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int asteroid : asteroids) {
            if (currMass < asteroid)
                return false;

            currMass += asteroid;
        }

        return true;
    }
};
