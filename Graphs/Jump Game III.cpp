// Problem: Jump Game III
// Platform: LeetCode
// Difficulty: Medium
// Topic: BFS, Graph Traversal

// Approach:
// - Use BFS starting from the given index.
// - From each index, try jumping:
//      1. i + arr[i]
//      2. i - arr[i]
// - Use a visited array to avoid infinite loops.
// - If any reached index contains 0, return true.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (arr[cur] == 0)
                return true;

            int forward = cur + arr[cur];
            int backward = cur - arr[cur];

            if (forward < n && !vis[forward]) {
                vis[forward] = true;
                q.push(forward);
            }

            if (backward >= 0 && !vis[backward]) {
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};
