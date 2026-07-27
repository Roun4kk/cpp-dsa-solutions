// Leetcode - 1464. Maximum Product of Two Elements in an Array
// topics - Mid Level, Array, Sorting, Heap (Priority Queue), Weekly Contest 191
// tc - O(n) 
// sc - O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0 ,second = 0 , oneCount = 0 , n = nums.size();
        for(auto it :  nums){
            if(it ==1 ){
                oneCount++;
                continue;
            }
            if(it>first){
                second = first;
                first = it ;
            }else{
                second = max(it , second);
            }
        }
        if(oneCount == n-1 || oneCount ==n)return 0;
        return (first - 1)* (second -1) ;
    }
};
