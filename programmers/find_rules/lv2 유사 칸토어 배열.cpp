#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;
// 어떤 경로를 거쳐서 number까지 도달하는지
vector<ll> getHistory(int n, ll number){
    vector<ll> history;
    if(number == 0){
        history.push_back(0);
        return history;
    }
    while(number > 0){
        history.push_back(number%5);
        number /= 5;
    }
    reverse(history.begin(), history.end());
    for(int i = 0; i<history.size(); i++){
        if(history[i] == 2){
            i++;
            while(i < history.size()){
                history[i] = 0;
                i++;
            }
        }
    }
    return history;
}

// 경로 역추적하며 1개수 계산
ll cal(vector<ll> history){
    // 해당 숫자 "앞에 있는" 1개수를 찾아줌
    ll count = history[0] - (history[0] > 2);
    for(int i = 1; i<history.size(); i++){// 1개수 : 이전 1개수 * 4
        count *= 4L;
        count += history[i] - (ll)((history[i]) > 2);    
    }
    return count;
}

int solution(int n, long long l, long long r) {
    vector<ll> historyL = getHistory(n, l-1), historyR = getHistory(n, r);

    ll left = cal(historyL);
    ll right = cal(historyR);
    return right - left;
}

/*
1
11011
11011 11011 00000 11011 11011
11011 11011 00000 11011 11011 / 11011 ...
28 - 5 - 1 - 0

...

4, 17
4는 0에 속해있음
17은 3에 속해있음

n=1에서 0,3에는 1101이 있음. 1이 3개, 0이 1개
n=2에서 3, 16이 됨
 0개수 = 8, 1개수=12
 3 이전에는 1이 2개, 0이 1개
 16 이후에는 1이 2개 0이 1개
 뺌 -> 0개수=8, 6
0 개수가 별로 안중요해


사실 구간 내에 0이 몇개 있는지만 알면 되는 거 아닌가?
그러면 그 index까지 0이 몇개 있는지만 알면 되는 거 아닌가?

1. 숫자를 n=1인 칸토어 배열까지 기록하며 당긴다.
2. 다시 복원하면서 0이 몇개 생기는지 본다.
   이전 0, 1의 개수로 현재 0, 1의 개수 연산
   현재 위치로 인해 생기는 0, 1의 개수 연산

예를 들어, 0부터 24까지 있는 n=2 배열에서
1. 3 -> 0이 된다.
2. 0 -> 3에서
   0 앞의 0 개수는 0개, 1 개수는 0개이다.
   나머지 연산, 3 % 5 = 3
   1 개수는 n개 - ((숫자 / 5) > 2), 0 개수는 ((숫자/5) > 2)
   1 개수는 3 - 1 = 2, 0 개수는 1개
   따라서 총 합 0 개수는 1개, 1 개수는 2개

1. 17 -> 3이 된다.
2. 3에서 -> 17
   3 앞의 0 개수는 1개, 1 개수는 2개이다. 
   0 개수는 1 * 5 + 1 * 2 = 7, 1 개수는 2 * 4 = 8
   
   나머지 연산, 17 % 5 = 2
   1 개수는 2, 0 개수는 0
   따라서 총 합 0 개수는 7개, 1 개수는 8 + 2 = 10개




*/