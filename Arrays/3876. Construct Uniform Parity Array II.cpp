// 3876. Construct Uniform Parity Array II
// topics - Senior, Array, Math
// Tc - O(n)
// Sc - O(1)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0 , evenCount = 0;
        int smallestEven = INT_MAX , smallestOdd = INT_MAX;
        for(auto it : nums1){
            if(it %2 == 0){
                evenCount++;
                smallestEven = min(smallestEven , it);
            }else{
                oddCount++;
                smallestOdd = min(smallestOdd , it);
            }
        }
        if(oddCount > 0){
            if(smallestEven < smallestOdd)return false;
        }
        return true ;
    }
};
