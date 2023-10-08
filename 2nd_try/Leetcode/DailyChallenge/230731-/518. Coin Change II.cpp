// time O(nm), space O(nm)
// Runtime 43 ms Beats 39.13%
// Memory 18.4 MB Beats 58.93%

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for(int i = 0; i<coins.size(); i++){
            dp[i][0] = 1;
            for(int j = 1; j<=amount; j++){
                if(i-1 >= 0) dp[i][j] = dp[i-1][j];
                if(j - coins[i] >= 0) dp[i][j] += dp[i][j-coins[i]];
            }
        }

        

        return dp[coins.size()-1][amount];
    }
};

// time O(nm) space O(m)
// Runtime 13 ms Beats 76.84%
// Memory 7.1 MB Beats 90.15%
class Solution {
public:
    int change(int amount, vector<int>& coins) {


        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i<coins.size(); i++){
            for(int j = 1; j<=amount; j++){
                if(j - coins[i] >= 0) dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};

/*
dp[i][j] : coin i까지 봤을 때 j원을 표기할 수 있는 개수
coin[i]로 j원 표기 가능 -> 1 더함
dp[i][j] = dp[i-1][j- coin[i-1]]

i 안쓰는 경우 - dp[i][j] = dp[i-1][j]
i 쓰는 경우   - dp[i][j] = dp[i][j-coin[i-1]]

1 2 5  / 5

  j 0 1 2 3 4 5
i
0   0 1 1 1 1 1
1     1 2 2 3 3
2   0 1 2 2 3 4

*/