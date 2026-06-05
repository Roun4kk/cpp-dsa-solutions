// Problem: Total Waviness of Numbers in a Range
// Platform: LeetCode
// Difficulty: Hard
// Topics: Digit DP

// Approach:
// - Use Digit DP with state:
//      dp[d][tight][start][l1][l2]
//   where:
//      d      = current digit position
//      tight  = whether current prefix matches the bound
//      start  = still processing leading zeros
//      l1     = previous digit
//      l2     = second previous digit
//
// - Store two values:
//      dp1 = total waviness contribution
//      dp2 = count of valid numbers
//
// - When at least three digits are formed,
//   check whether the current digit continues
//   the alternating up/down pattern.
//
// - Compute answer for [0, x] using Digit DP.
// - Range answer:
//      solve(num2) - solve(num1 - 1)
//
// Time Complexity:
// O(17 * 2 * 2 * 12 * 12 * 10)
//
// Space Complexity:
// O(17 * 2 * 2 * 12 * 12)

class Solution {
public:
    long long solve(long long x) {
        static long long dp1[17][2][2][12][12];
        static long long dp2[17][2][2][12][12];

        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        string s = to_string(x);
        int n = s.length();

        for (int d = n; d >= 0; d--) {
            for (int start = 0; start < 2; start++) {
                for (int tight = 0; tight < 2; tight++) {
                    for (int l1 = 0; l1 < 12; l1++) {
                        for (int l2 = 0; l2 < 12; l2++) {

                            if (d == n) {
                                dp1[d][tight][start][l1][l2] = 0;
                                dp2[d][tight][start][l1][l2] = 1;
                                continue;
                            }

                            long long ss = 0;
                            long long c = 0;

                            int limit = (tight ? s[d] - '0' : 9);

                            for (int i = 0; i <= limit; i++) {
                                bool a = start && (!i);

                                long long ans[] = {
                                    dp1[d + 1][tight && (i == limit)][a][a ? 11 : i][a ? 11 : l1],
                                    dp2[d + 1][tight && (i == limit)][a][a ? 11 : i][a ? 11 : l1]
                                };

                                if (!start && l1 != 11 && l2 != 11) {
                                    if ((l1 > l2 && l1 > i) ||
                                        (l1 < l2 && l1 < i)) {
                                        ss += ans[1];
                                    }
                                }

                                c += ans[1];
                                ss += ans[0];
                            }

                            dp1[d][tight][start][l1][l2] = ss;
                            dp2[d][tight][start][l1][l2] = c;
                        }
                    }
                }
            }
        }

        return dp1[0][1][1][11][11];
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
