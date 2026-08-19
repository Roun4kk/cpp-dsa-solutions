// 1386. Cinema Seat Allocation
// Topics - Senior, Array, Hash Table, Greedy, Bit Manipulation
// TC - O(mlogm)
// SC - O(1)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size() ;
        sort(reservedSeats.begin() , reservedSeats.end());
        int lastRow = 0 , currentRow = 0 , i = 0;
        int ans = 0;
        while(i <m){
            currentRow = reservedSeats[i][0];
            ans += (currentRow - lastRow -1)*2;
            bool blockA = true , blockB = true , blockC= true;
            while(i<m && reservedSeats[i][0] == currentRow){
                int currentSeat = reservedSeats[i][1];
                if(currentSeat>=2 && currentSeat<=5)blockA = false; 
                if(currentSeat>=4&& currentSeat<=7)blockB = false; 
                if(currentSeat>=6 && currentSeat<=9)blockC = false; 
                i++;
            }
            if(blockA && blockC){
                ans+=2;
            }else if(blockA || blockB || blockC )ans+=1;
            lastRow = currentRow;
        }
        if(lastRow != n){
            ans += (n -lastRow) *2;
        }
        return ans ;
    }
};
