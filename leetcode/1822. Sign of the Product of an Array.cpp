// Runtime 7 ms Beats 57.19%
// Memory 10.2 MB Beats 45.94%

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int isNegative = 1;
        for(int n : nums){
            if(n == 0) return 0;
            if(n < 0) isNegative *= -1;
        }
        return isNegative;
    }
};