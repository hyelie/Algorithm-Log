#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int len;

int solution(vector<int> sticker)
{
    len = sticker.size();
    if(len <= 3) return *max_element(sticker.begin(), sticker.end());
    
    vector<int> dp(len, 0);
    
    // case 1. 0번째 것 뜯는 경우
    dp[0] = sticker[0];
    dp[1] = dp[0];
    dp[2] = dp[0] + sticker[2];
    for(int i = 3; i<len-1; i++){
        dp[i] = max(dp[i-1], sticker[i] + max(dp[i-2], dp[i-3]));
    }
    int answer = *max_element(dp.begin(), dp.end());
    
    // case 2. 0번째 것 뜯지 않는 경우
    fill(dp.begin(), dp.end(), 0);
    dp[0] = 0;
    dp[1] = sticker[1];
    dp[2] = dp[1];
    for(int i = 3; i<len; i++){
        dp[i] = max(dp[i-1], sticker[i] + max(dp[i-2], dp[i-3]));
    }
    answer = max(answer, *max_element(dp.begin(), dp.end()));

    return answer;
}

/*
DP?
dp[i] : i번째 스티커까지 봤을 때 최댓값?
i번째 스티커 뜯었을 때 최댓값?

뜯엇을 때라고 보자고.
dp[i] =
dp[i-1]
dp[i-2] + sticker[i]
dp[i-3] + sticker[i]

1. 0번째 것을 뜯는 경우
dp[0] = sticker[0]으로 시작 : 
dp[n-2]까지만 봐야 함.

2. 0번째 것을 뜯지 않는 경우
dp[0] = 0으로 시작
*/