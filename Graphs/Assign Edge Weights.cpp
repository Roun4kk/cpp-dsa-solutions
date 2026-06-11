// Problem: Assign Edge Weights
// Platform: LeetCode
// Difficulty: Medium
// Topics: Tree, BFS, Graph, Math

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    static constexpr int mod = 1000000007;

    long long modPow(long long base, int exp) {
        long long res = 1;

        while (exp) {
            if (exp & 1)
                res = res * base % mod;

            base = base * base % mod;
            exp >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int depth = 0;
        vector<vector<int>> adj(edges.size() + 2);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        unordered_set<int> vis;

        q.push(1);
        vis.insert(1);

        while (!q.empty()) {
            depth++;
            int sz = q.size();

            while (sz--) {
                int node = q.front();
                q.pop();

                for (int nxt : adj[node]) {
                    if (vis.count(nxt))
                        continue;

                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        return modPow(2, depth - 2);
    }
};
