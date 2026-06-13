// Problem: Weighted Word Mapping
// Platform: LeetCode
// Difficulty: Easy
// Topics: String, Array, Simulation

// Time Complexity: O(total characters in all words)
// Space Complexity: O(1)

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto& word : words) {
            int weight = 0;

            for (char ch : word) {
                weight += weights[ch - 'a'];
            }

            weight %= 26;
            ans.push_back('a' + (25 - weight));
        }

        return ans;
    }
};
