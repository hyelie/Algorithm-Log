// Runtime 3 ms Beats 50.37%
// Memory 6.7 MB Beats 20.91%

class Solution {
public:
    vector<int> nums;
    int INF = -1;
    vector<int> dp;

    int recurse(int remain){
        if(dp[remain] != INF) return dp[remain];

        int num_cases = 0;
        for(int n : nums){
            if(n > remain) break;
            num_cases += recurse(remain - n);
        }
        dp[remain] = num_cases;
        return dp[remain];
    }
    int combinationSum4(vector<int>& i_nums, int target) {
        nums = i_nums;
        dp.resize(target + 1, INF);
        dp[0] = 1;
        sort(nums.begin(), nums.end(), less<int>());

        return recurse(target);
    }
};