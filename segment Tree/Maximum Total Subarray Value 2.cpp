// Problem: Maximum Total Subarray Value I
// Platform: LeetCode
// Difficulty: Hard
// Topics: Segment Tree, Priority Queue, Greedy

// Time Complexity: O((n + k) log n)
// Space Complexity: O(n)

class Solution {
public:
    class segTree {
    public:
        vector<int> treeMin, treeMax;

        segTree(int n) {
            treeMin.resize(4 * n);
            treeMax.resize(4 * n);
        }

        void createMin(int l, int r, int i, vector<int>& nums) {
            if (l == r) {
                treeMin[i] = l;
                return;
            }

            int mid = (l + r) / 2;
            createMin(l, mid, 2 * i + 1, nums);
            createMin(mid + 1, r, 2 * i + 2, nums);

            treeMin[i] =
                (nums[treeMin[2 * i + 1]] < nums[treeMin[2 * i + 2]]
                     ? treeMin[2 * i + 1]
                     : treeMin[2 * i + 2]);
        }

        void createMax(int l, int r, int i, vector<int>& nums) {
            if (l == r) {
                treeMax[i] = l;
                return;
            }

            int mid = (l + r) / 2;
            createMax(l, mid, 2 * i + 1, nums);
            createMax(mid + 1, r, 2 * i + 2, nums);

            treeMax[i] =
                (nums[treeMax[2 * i + 1]] > nums[treeMax[2 * i + 2]]
                     ? treeMax[2 * i + 1]
                     : treeMax[2 * i + 2]);
        }

        int findMin(int l, int r, int s, int e, int i, vector<int>& nums) {
            if (r < s || l > e)
                return -1;

            if (l >= s && r <= e)
                return treeMin[i];

            int mid = (l + r) / 2;

            int left = findMin(l, mid, s, e, 2 * i + 1, nums);
            int right = findMin(mid + 1, r, s, e, 2 * i + 2, nums);

            if (left == -1) return right;
            if (right == -1) return left;

            return (nums[left] < nums[right] ? left : right);
        }

        int findMax(int l, int r, int s, int e, int i, vector<int>& nums) {
            if (r < s || l > e)
                return -1;

            if (l >= s && r <= e)
                return treeMax[i];

            int mid = (l + r) / 2;

            int left = findMax(l, mid, s, e, 2 * i + 1, nums);
            int right = findMax(mid + 1, r, s, e, 2 * i + 2, nums);

            if (left == -1) return right;
            if (right == -1) return left;

            return (nums[left] > nums[right] ? left : right);
        }
    };

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        };

        priority_queue<vector<int>,
                       vector<vector<int>>,
                       decltype(cmp)> pq(cmp);

        segTree st(n);

        st.createMin(0, n - 1, 0, nums);
        st.createMax(0, n - 1, 0, nums);

        for (int i = 0; i < n; i++) {
            int mx = st.findMax(0, n - 1, i, n - 1, 0, nums);
            int mn = st.findMin(0, n - 1, i, n - 1, 0, nums);

            int val = nums[mx] - nums[mn];
            pq.push({val, i, n - 1});
        }

        long long ans = 0;

        while (k && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            ans += cur[0];
            k--;

            if (cur[1] >= cur[2])
                continue;

            int mx =
                st.findMax(0, n - 1, cur[1], cur[2] - 1, 0, nums);
            int mn =
                st.findMin(0, n - 1, cur[1], cur[2] - 1, 0, nums);

            int val = nums[mx] - nums[mn];

            pq.push({val, cur[1], cur[2] - 1});
        }

        return ans;
    }
};
