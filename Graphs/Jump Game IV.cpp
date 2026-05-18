// Problem: Jump Game IV
// Platform: LeetCode
// Difficulty: Hard
// Topic: BFS, Graph, Hash Map

// Approach:
// Treat each index as a node.
// From index i, we can move to:
// 1. i - 1
// 2. i + 1
// 3. Any index j where arr[i] == arr[j]
//
// Since every move costs exactly 1,
// BFS guarantees the shortest path.
//
// Optimization:
// After processing all indices having the same value,
// clear the vector to avoid repeated traversals.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, int>> q;

        q.push({0, 0});

        dist[0] = 0;

        while (!q.empty()) {

            int jumps = q.front().first;
            int i = q.front().second;

            q.pop();

            if (i == n - 1)
                return jumps;

            // Move to i - 1
            if (i - 1 >= 0 && dist[i - 1] > jumps + 1) {

                dist[i - 1] = jumps + 1;

                q.push({jumps + 1, i - 1});
            }

            // Move to i + 1
            if (i + 1 < n && dist[i + 1] > jumps + 1) {

                dist[i + 1] = jumps + 1;

                q.push({jumps + 1, i + 1});
            }

            // Move to same value indices
            for (auto j : mp[arr[i]]) {

                if (j == i)
                    continue;

                if (dist[j] > jumps + 1) {

                    dist[j] = jumps + 1;

                    q.push({jumps + 1, j});
                }
            }

            // Prevent repeated traversal
            mp[arr[i]].clear();
        }

        return -1;
    }
};
