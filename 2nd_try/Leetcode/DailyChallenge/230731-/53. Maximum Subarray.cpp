// Runtime 76 ms Beats 96.56%
// Memory 67.7 MB Beats 32.89%

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int answer = -1e9, sum = 0;
        for(int i = 0; i<n; i++){
            sum = max(nums[i], sum + nums[i]);
            answer = max(answer, sum);
        }

        return answer;
    }
};