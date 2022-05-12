// 스티커 모으기(2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() == 1) return sticker[0];
    vector<int> dp(sticker.size()+1, 0);
    // 0번 선택 경우 - 마지막 것 선택 못함
    dp[0] = dp[1] = sticker[0];
    for(int i = 2; i<sticker.size() - 1; i++){
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    int answer = *max_element(dp.begin(), dp.end());
    
    // 1번 선택 경우 - 0번 선택 못함
    dp[0] = 0; dp[1] = sticker[1];
    for(int i = 2; i<sticker.size(); i++){
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    }
    
    answer = max(*max_element(dp.begin(), dp.end()), answer);

    return answer;
}

// dp[i] : i번째 스티커까지 봤을 때 최댓값