// 2958. Length of Longest Subarray With at Most K Frequency
// topic - Array, Hash Table, Sliding Window
// tc - O(n) 
// sc - O(n)
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int j = 0 , n = nums.size();
        unordered_map<int,int> mp;
        int ans  =0 ;
        for(int i = 0 ;i<n ;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            ans  = max(ans ,i-j+1);
        }
        return ans ;
    }
};
