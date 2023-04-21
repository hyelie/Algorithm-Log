typedef long long ll;

class Solution {
public:
    int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int planSize = group.size();
        vector<vector<vector<ll>>> dp(planSize + 1, vector<vector<ll>>(n+1, vector<ll>(minProfit + 1, 0)));

        dp[0][0][0] = 1;
        for(int i = 1; i<=planSize; i++){
            for(int j = 0; j<=n; j++){
                for(int k = 0; k<=minProfit; k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j >= group[i-1]){
                        int newK = k-profit[i-1] <= 0 ? 0 : k-profit[i-1];
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-group[i-1]][newK]) % MOD;
                    }
                }
            }
        }

        ll answer = 0;
        for(int j = 0; j<n+1; j++){
            answer = (answer + dp[planSize][j][minProfit]) % MOD;
        }
        return (int)answer;
    }
};

/*
DP...
knapsack같은데? i부터 j까지 k명 썼을 때 가능한 개수
dp[i][j][k]
i부터 j까지 k명 썼을 때 가능한 개수 ? 음... 모든 case에 대해 얼마 썼는지가 있어야 다음 경우 계산할 수 있다.
i부터 j까지 k원 썼을 때 가능한 개수 ? 음... 모든 case에 대해 몇명을 썼는지가 있어야 다음 경우를 계산할 수 있따.
즉, 몇 번째 plan까지 사용했는지를 저장하는 건 안된다. 그러면 0부터 i까지 plan을 봤다고 치자.
그러면 일반적으로 이런 DP 문제의 항은 문제에서 주어진 대로니까 j를 몇 명 썼는지, k는 minProfit으로 나타내 보자.

그러면 0부터 i까지 plan을 봤을 때, j명으로 k원 이상을 사용하는 가능한 경우의 수

i를 계산할 때, i-1을 쓰는 경우가 있고, 안 쓰는 경우가 있을 것
안 쓰는 경우 : dp[i][j][k] = dp[i-1][j][k]
쓰는 경우 : dp[i][j][k] = dp[i-1][j-group[i]][k-profit[i]]
dp[i][j][k]는 이 둘의 합이 될 것임. knapsack과 아주 유사하네?

i번째 plan을 넣을 수 있다면 (j - group[i]) 넣자.
k - profit[i]가 0보다 작다면 0으로 바꾸자. 0원 이하을 사용하는 경우의 수는 항상 0원을 사용하는 경우와 동일하기 때문.

초기값은 dp[0][0][0] = 1이다. 0명으로 0원 이상을 사용하는 가능한 경우의 수 = 항상 1. (아무것도 안고르기)
*/