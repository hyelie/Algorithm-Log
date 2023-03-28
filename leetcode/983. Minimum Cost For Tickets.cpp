// Runtime 4 ms Beats 69.83%
// Memory 9.6 MB Beats 81.2%

class Solution {
public:
    int handleOutbound(int day, int value){
        if(day - value < 0) return 0;
        return day - value;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int INF = days[days.size()-1] + 1;
        cout<<INF<<endl;
        vector<int> dp(INF, 0);
        for(int i = 1, didx = 0; i<INF; i++){
            dp[i] = dp[i-1];
            if(didx < days.size() && days[didx] == i){
                dp[i] += costs[0];
                didx++;
            }
            dp[i] = min(dp[i], dp[handleOutbound(i, 7)] + costs[1]);
            dp[i] = min(dp[i], dp[handleOutbound(i, 30)] + costs[2]);
        }
        
        return dp[INF-1];
    }
};