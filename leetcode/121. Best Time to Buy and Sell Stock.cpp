// Runtime 128ms, Beats 88.61%
// Memory 93.3MB, Beats 56.82%

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // 초기 접근, array 이용
        // vector<int> dp(n, INT_MAX);
        // int answer = INT_MIN;
        // for(int i = 1; i<n; i++){
        //     dp[i] = min(dp[i-1], prices[i-1]);
        //     answer = max(answer, prices[i] - dp[i]);
        // }

        // 굳이 array 쓸 필요 없음
        int prevMinValue = INT_MAX, answer = INT_MIN;
        for(int i = 1; i<n; i++){
            prevMinValue = min(prevMinValue, prices[i-1]);
            answer = max(answer, prices[i] - prevMinValue);
        }

        return answer < 0 ? 0 : answer; // 실수 : profit 얻지 못할 경우 계산하지 않음
    }
};