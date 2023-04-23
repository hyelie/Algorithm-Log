typedef long long ll;

class Solution1 {
public:
    int n, MOD = 1e9+7;
    int recurse(string& s, int k, vector<int>& dp, int i){
        if(i == n) return 1; // base case
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;
        
        ll result = 0;
        ll createdNumber = 0;
        // i를 시작점으로 k까지 늘려가며 숫자를 만듬
        for(int j = i; j<s.length(); j++){
            createdNumber = 10 * createdNumber + s[j] - '0';
            if(createdNumber > k) break;
            result = (result + recurse(s, k, dp, j+1)) % MOD; // *** 탐색 가능하다면 그 값 더함
        }
        dp[i] = result;
        return dp[i];
    }
    int numberOfArrays(string s, int k) {
        n = s.length();
        // dp[i] : i부터 n까지 가능한 경우의 수
        vector<int> dp(s.length(), -1);

        return recurse(s, k, dp, 0);
    }
};

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int MOD = 1e9+7;
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 1; // base case

        ll result, createdNumber;
        for(int i = n-1; i>=0; i--){ // *** dp[i]는 i보다 큰 j에 대해 dp[j]에 depend하므로 n-1부터 0까지 순서로 계산해야 함
            if(s[i] == '0') continue;
            result = 0; createdNumber = 0;
            // i를 시작점으로 k까지 늘려가며 숫자를 만듬
            for(int j = i; j<n; j++){
                createdNumber = 10 * createdNumber + s[j] - '0';
                if(createdNumber > k) break;
                result = (result + dp[j+1]) % MOD; // *** 탐색 가능하다면 그 값 더함
            }
            dp[i] = result;
        }
        return dp[0];
    }
};