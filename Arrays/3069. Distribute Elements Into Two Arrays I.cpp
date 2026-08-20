// 3069. Distribute Elements Into Two Arrays I
// Topics - Array
// Platform - Leetcode
// Tc - O(n)
// Sc - O(n)
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 , arr2;
        for(auto it : nums){
            if(arr1.empty()){
                arr1.push_back(it);
            }else if (arr2.empty()){
                arr2.push_back(it);
            }else{
                if(arr1.back() > arr2.back()){
                    arr1.push_back(it);
                }else{
                    arr2.push_back(it);
                }
            }
        }
        for(auto it : arr2){
            arr1.push_back(it);
        }
        return arr1;
    }
};
