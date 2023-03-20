// Runtime 10 ms Beats 97.73%
// Memory 20.3 MB Beats 76.11%

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, len = flowerbed.size();
        while(1){
            if(i >= len || len <= 0) break;
            if(flowerbed[i] == 0){
                
                if(i+1 >= len || (i+1 < len && flowerbed[i+1] == 0)){
                    n--;
                    i += 2;
                }
                else i++;
            }
            else{
                i += 2;
            }
        }

        return n <= 0;
    }
};