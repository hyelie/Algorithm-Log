// Runtime 141 ms Beats 55.87%
// Memory 49.8 MB Beats 58.53%

class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len - 1;
        sort(nums.begin(), nums.end(), less<int>());
        
        // for efficiency, pre-calculate pow of 2's
        vector<int> pows(len);
        pows[0] = 1;
        for(int i = 1; i<len; i++){
            pows[i] = (2*pows[i-1]) % MOD;
        }

        int answer = 0;
        while(left <= right){
            if(nums[left] + nums[right] <= target){
                answer = (answer + pows[right - left]) % MOD; // nums[left]를 포함하고, left + 1부터 right까지 subset에 nums[left]를 합치면 문제 조건에 인정됨.
                left++;
            }
            else{
                right--;
            }
        }
        return answer;
    }
};