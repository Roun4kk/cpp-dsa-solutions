// Problem: Find the Prefix Common Array of Two Arrays
// Platform: LeetCode
// Difficulty: Medium
// Topic: Hashing, Array

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        unordered_set<int> set1;
        unordered_set<int> set2;

        vector<int> ans(n);

        int common = 0;

        for (int i = 0; i < n; i++) {
            set1.insert(A[i]);
            set2.insert(B[i]);

            if (A[i] == B[i]) {
                common++;
            } 
            else {
                if (set1.count(B[i]))
                    common++;

                if (set2.count(A[i]))
                    common++;
            }

            ans[i] = common;
        }

        return ans;
    }
};
