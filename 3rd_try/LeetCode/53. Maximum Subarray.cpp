class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), -1e9);
        dp[0] = max(nums[0], dp[0]);
        for(int i = 1; i<nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};