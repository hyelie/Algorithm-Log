#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve(vector<int> &times){
    // 문제 조건
    vector<int> dp(times.size(), 0);
    vector<string> backtrack(times.size(), "");

    // if times.length() < 3 then answer = times[i]
    for(int i = 0; i<3; i++){
        dp[i] = times[i];

        backtrack[i] = to_string(i+1) + backtrack[i];
    }
    // else use dp
    for(int i = 3; i<times.size(); i++){
        dp[i] = times[i] + min(dp[i-1], min(dp[i-2], dp[i-3]));

        int minValue = min(dp[i-1], min(dp[i-2], dp[i-3]));
        if(minValue == dp[i-3]){
            backtrack[i] = backtrack[i-3] + " ";
        }
        else if(minValue == dp[i-2]){
            backtrack[i] = backtrack[i-2] + " ";
        }
        else if(minValue == dp[i-1]){
            backtrack[i] = backtrack[i-1] + " ";
        }
        backtrack[i] = backtrack[i] + to_string(i+1);
    }
    cout<<"total size: "<<times.size()<<endl;
    cout<<"answer: "<<dp[times.size()-1]<<endl;
    cout<<"track result: "<<backtrack[backtrack.size()-1]<<endl;
    return;
}

int main(){
    vector<int> times = {13, 8, 11, 7, 9, 17, 12, 14, 19, 15, 16, 15, 15, 13, 14}; // 문제
    // vector<int> times = {10, 20, 15, 25, 10, 20}; // 예제

    // 1번에서 출발해 1번을 찍고 도착하는 경우
    for(int i = times.size()-2; i>=0; i--){
        times.push_back(times[i]);
    }
    solve(times);
    return 0;
}

/*
점화식이 어떻게 될까
1) x를 들르면 x+1, x+2, x+3 중 하나는 방문해야 한다.
2) 마지막에는 무조건 방문해야 한다. 이 때 1, 2, ... , 14, 15, 14, 13, ... 1의 순서로 방문하기 때문에 1번을 제일 마지막으로 방문해야 한다.

점화식을 잡아보자.
dp[i] : i를 들렀을 때 점검 시간 합의 최소값

if times.length() < 3 then answer = times[i]
else use dp
dp[i] = times[i] + min(dp[i-1], dp[i-2], dp[i-3]);


출력값은
answer: 122
track result: 1 4 7 10 13 16 19 22 25 28
이다. 이 때 track result는 0부터 세기 때문에 모든 값에 1을 더한다. 그러면
1 4 7 10 13 16 19 22 25 28에서
2 5 8 11 14 17 20 23 26 29가 된다.
이 때 15를 넘는 것은 30에서 그 값을 빼야 한다.
2 5 8 11 14 17 20 23 26 29에서
2 5 8 11 14 13 10 7 4 1가 된다.

*/