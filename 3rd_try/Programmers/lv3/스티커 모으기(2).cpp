#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stickers)
{
    int len = stickers.size();
    vector<int> dp1(len, 0), dp2(len, 0);
    
    // dp1 : 첫 번째 것 뜯고 마지막 것 못 뜯음
    dp1[0] = stickers[0];
    if(len >= 2) dp1[1] = stickers[1];
    if(len >= 3) dp1[2] = dp1[0] + stickers[2];
    for(int i = 3; i<len-1; i++){
        dp1[i] = max(dp1[i-2], dp1[i-3]) + stickers[i];
    }
    
    // dp2 : 첫 번째 것 뜯지 않음
    dp2[0] = 0;
    if(len >= 2) dp2[1] = stickers[1];
    if(len >= 3) dp2[2] = stickers[2];
    for(int i = 3; i<len; i++){
        dp2[i] = max(dp2[i-2], dp2[i-3]) + stickers[i];
    }
    
    return max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()));
}

// dp 2번.
// dp[i] : i칸 뜯었을 때 최대값
// dp[i] = max(dp[i-2], dp[i-3]) + sticker[i]