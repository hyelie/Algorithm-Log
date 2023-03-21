// Runtime 162 ms Beats 86.73%
// Memory 107.5 MB Beats 86.43%

typedef long long ll;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll answer = 0;

        for(int i = 0; i<nums.size(); i++){
            ll cnt = 0;
            while(i < nums.size() && nums[i] == 0){
                i++;
                cnt++;
                answer += cnt;
            }
        }

        return answer;
    }
};