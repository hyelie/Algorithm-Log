// Runtime 32 ms Beats 85.55%
// Memory 15.3 MB Beats 14.89%

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // dp
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i = 1; i<=len1; i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int j = 1; j<=len2; j++) dp[0][j] = dp[0][j-1] + s2[j-1];

        for(int i = 1; i<=len1; i++){
            for(int j = 1; j<=len2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
            }
        }
        
        return dp[len1][len2];
    }
};

/*
LCS를 찾는 문제. LCS의 길이 뿐만 아니라 그 값도 찾아야 하므로, DP 역추적이다.
dp[i][j] : s1의 length i까지, s2의 length j까지 봤을 때 LCS의 

+ LCS의 값이 더 크게 설정되어야 함.

-> 이렇게 풀면 LCS의 모든 경우를 세서 제일 큰 걸 골라야 함. 음... 아닌 것 같다.

1.
dp[i][j] : s1의 length i까지, s2의 length j까지 봤을 때 답.
lcs인 부분, 그러니까 겹치는 부분만 빼면 된다고 생각하면 될 것 같다.
s1[i] == s2[j]면 그 string 안더해도 되므로 이전 값과 동일. 
else면 이전 값 중 min값

2.
1.과 같이 풀 수 있다는 것은, 거꾸로 말해 LCS의 sum을 최대로 만들 수도 있다는 것이다.
1.의 접근보다 더 떠올리기 쉬운 접근이다.
*/

// Runtime 26 ms Beats 88.95%
// Memory 15.1 MB Beats 68.25%

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // dp
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i = 1; i<=len1; i++){
            for(int j = 1; j<=len2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // calculate
        int answer = 0;
        for(char c : s1) answer += c;
        for(char c : s2) answer += c;

        return answer - 2*dp[len1][len2];
    }
};