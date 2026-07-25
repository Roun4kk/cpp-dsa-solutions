// Leetcode - 3536. Maximum Product of Two Digits
// topics - Mid Level , Math , Sorting ,Weekly Contest 448
// tc -  O(n)
// sc -  O(1)
class Solution {
public:
    int maxProduct(int n) {
        int largest = 0 , secondLargest = 0;
        while(n){
            int currentDigit = n%10;
            if(currentDigit>largest){
                secondLargest = largest;
                largest = currentDigit;
            }else{
                secondLargest = max(currentDigit , secondLargest);
            }
            n/=10;
        }
        return largest * secondLargest;
    }
};
