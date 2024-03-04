#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll dp(vector<ll> &seq){
    ll sum = 0, len = seq.size();
    vector<ll> dp(len, 0);
    
    dp[0] = max(seq[0], 0LL);
    for(int i = 1; i<len; i++){
        dp[i] = max(seq[i], dp[i-1] + seq[i]);
    }
    
    return *max_element(dp.begin(), dp.end());
}

ll solution(vector<int> sequence) {
    int len = sequence.size();
    vector<ll> dp1(sequence.begin(), sequence.end()), dp2(sequence.begin(), sequence.end());
    for(int i = 0; i<len; i += 2){
        dp1[i] *= -1;
        if(i+1 < len) dp2[i+1] *= -1;
    }
    return max(dp(dp1), dp(dp2));
}

/*
backtracking - X
DP
greedy

펄스 수열 곱한 전체 배열에서 연속합의 최댓값을 구함.
1, -1에 대해 2번 수행함.
이러면 되는거 아닌가?

연속합의 최댓값 <- 이거 어떻게 구함? DP 아님?

1) psum 구하고ㅗ
*/