class Solution {
public:
    int n; // 전체 길이
    vector<int> dp;
    int INF = 987654321;
    int cal(int cur_idx, vector<int>& nums){ // cur_idx에서 뛰어서 n-1에 도달하는 최소값
        if(dp[cur_idx] != INF) return dp[cur_idx];
        if(cur_idx == n-1){
            return 0;
        }

        int can_jump = nums[cur_idx];
        int min_value = INF;
        // 갈 수 있는 모든 칸들에 대해
        // 그 칸에서 n-1까지 가는 최소값 + 여기서 그 칸까지 가는 값(1)
        for(int i = cur_idx + 1; i<=cur_idx + can_jump && i < n; i++){
            min_value = min(min_value, cal(i, nums) + 1);
        }
        dp[cur_idx] = min_value;
        return dp[cur_idx];
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n);
        fill(dp.begin(), dp.end(), INF);
        dp[n-1] = 0;

        return cal(0, nums);
    }
};