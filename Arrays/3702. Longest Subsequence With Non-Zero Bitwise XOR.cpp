// 3702. Longest Subsequence With Non-Zero Bitwise XOR
// platform : leetcode
// difficulty : medium (i think easy)
// tc : O(n)
// sc : O(1)

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int i = 0 ;
        for(auto it : nums){
            i ^=it;
        }
        if(i > 0)return nums.size() ;
        for(auto it : nums){
            if(i ^it >0)return nums.size() -1;
        }
        return 0;
    }
};
