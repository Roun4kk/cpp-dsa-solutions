// Leetcode - 3514. Number of Unique XOR Triplets II
// topics - Staff, Array, Math, Bit Manipulation, Enumeration, Biweekly Contest 154
// tc - O(n^2)
// sc - 0(n)
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ;
        unordered_set<int>st , pt;
        for(int i =0;i< n ;i++){
            for(int j = i; j <n ;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        for(auto it : nums){
            for(auto bt :  st){
                pt.insert(it^bt);
            }
        }
        return pt.size();
    }
};
