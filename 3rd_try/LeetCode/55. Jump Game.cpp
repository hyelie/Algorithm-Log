class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> nums;
    int UNVISITED = -1, FALSE = 0, TRUE = 1;
    bool recurse(int i){ // i에서 뛰었을 때 가능한지 여부
        if(i == n-1) return true;
        if(dp[i] != UNVISITED) return dp[i];

        bool result = false;;
        for(int k = i+1; k<=i+nums[i]; k++){
            if(recurse(k)){
                result = true;
                break;
            }
        }

        dp[i] = result;
        return result;
    }
    bool canJump(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        dp.resize(n);
        fill(dp.begin(), dp.end(), UNVISITED);

        return recurse(0);
    }
};