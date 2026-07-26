// 628. Maximum Product of Three Numbers
// topics - Mid Level, Array, Math, Sorting
// tc - o(nlogn) 
// sc - o(1)
// it can be done in o(n) tc , just need to check if second smallest element is negative or not , if it is then same max of
// smallest * secondSmallest * largest , largest * secondLargest * thirdLargest .
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        return max(nums[0]*nums[1]*nums[n-1] , nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
