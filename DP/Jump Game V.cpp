// Problem: Jump Game V
// Platform: LeetCode
// Difficulty: Hard
// Topic: Dynamic Programming, DFS, Memoization

// Time Complexity: O(n * d)
// Space Complexity: O(n)

class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];

        int ans = 1;
        int n = arr.size();

        // Move Right
        for (int nxt = i + 1; nxt <= min(n - 1, i + d); nxt++) {
            if (arr[nxt] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(nxt, arr, d, dp));
        }

        // Move Left
        for (int nxt = i - 1; nxt >= max(0, i - d); nxt--) {
            if (arr[nxt] >= arr[i])
                break;

            ans = max(ans, 1 + dfs(nxt, arr, d, dp));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};
