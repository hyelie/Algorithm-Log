#include <string>
#include <vector>
#include <climits>

using namespace std;
typedef pair<int, int> pii; // .first : 던진 회수, .second : 싱글/불 회수 합

// dp[i]와 dp[i + p]를 비교 후 dp값을 채워넣음
void calNext(vector<pii> &dp, int i, int p, bool isSingleOrBull){
    if(i + p < dp.size()){
        if(dp[i + p].first == dp[i].first + 1){
            dp[i + p].second = max(dp[i + p].second, dp[i].second + isSingleOrBull);
        }
        else if(dp[i + p].first > dp[i].first + 1){
            dp[i + p].first = dp[i].first + 1;
            dp[i + p].second = dp[i].second + isSingleOrBull;
        }
    }
}

vector<int> solution(int target) {
    vector<pii> dp(target+1, {INT_MAX, INT_MIN});
    dp[0] = {0, 0};
    for(int i = 0; i<=target; i++){
        // 1 ~ 20점
        for(int p = 1; p<=20; p++){
            calNext(dp, i, p, true); // 1배
            calNext(dp, i, 2*p, false); // 2배
            calNext(dp, i, 3*p, false); // 3배
        }
        // 50점
        calNext(dp, i, 50, true);
    }
    
    vector<int> answer(2);
    answer[0] = dp[target].first; answer[1] = dp[target].second;
    return answer;
}

/*
1 ~ 20
1배, 2배, 3배
동 점수라면 싱글/불을 더 많이 맞추어야 함
DP같은데?
dp[i] : 점수 i에 대해 [맞춘 회수, 싱글/불 회수 합]이라고 두면
for i = 1 to 20
    dp[i] = min(dp[i], dp[i-1] + 1)
    if(dp[i] == dp[i-1] + 1) dp[i].second = dp[i-1].second + 1
    if(dp[i] > dp[i-1] + 1) dp[i] = dp[i-1]
*/