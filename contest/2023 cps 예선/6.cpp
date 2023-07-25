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
    cout<<"answer: "<<dp[times.size()-1]<<endl;
    cout<<"track result: "<<backtrack[backtrack.size()-1]<<endl;
    return;
}

int main(){
    vector<int> forward = {13, 8, 11, 7, 9, 17, 12, 14, 19, 15, 16, 15, 15, 13, 14}; // 문제
    // vector<int> times = {10, 20, 15, 25, 10, 20}; // 예제

    // 15번을 찍는 경우 시간 최소값 계산
    cout<<"갈 때"<<endl;
    solve(forward);

    // 15번을 찍은 상태에서 출발점으로 되돌아온다.
    vector<int> backward = {};
    for(int i = forward.size()-2; i>=0; i--){
        backward.push_back(forward[i]);
    }
    backward.push_back(0); // 단, 출발점으로 돌아올 때는 1번 센터를 들르지 않아도 괜찮으므로 점검 시간이 0인 0번 센터를 추가하고, 0번 센터로 돌아오는 최소 시간을 계산한다.
    
    cout<<"돌아올 때"<<endl;
    solve(backward);
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


갈 때
answer: 71
track result: 2 4 7 10 12 15
돌아올 때
answer: 57
track result: 2 5 8 11 13 15
돌아올 때는 센터 번호를 역순으로 넣었기 때문에 15에서 그 값을 빼야 한다.
track result: 2 5 8 11 13 15
-> 13 10 7 4 2 0

즉, 전체 경로는
2 4 7 10 12 15
13 10 7 4 2 0
총 계 128이다.


*/