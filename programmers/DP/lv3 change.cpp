// 거스름돈

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int MOD = 1000000007;


int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    vector<int> dp(n+1, 0);
     // 제일 작은 돈 단위로 계산할 때
    dp[0] = 1;
    for(int i = money[0]; i<=n; i += money[0]){
        dp[i] = 1;
    }
    
    for(int m = 1; m<money.size(); m++){
        for(int i = 1; i<=n; i++){
            if(i - money[m] >= 0) dp[i] += dp[i - money[m]];
        }
    }
    
    // dp[i] = dp[i - m1] + dp[i - m2] + ... + dp[i-mk]
    
    return dp[n];
}