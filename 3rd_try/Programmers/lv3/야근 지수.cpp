#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef long long ll;

map<int, int> m; // [n시간, n시간 작업 개수]

long long solution(int n, vector<int> works) {
    for(int work : works) m[work]++;
    
    // 제일 큰 수를 1 줄이는 게 가장 효율적임.
    // 큰 것부터 1씩 줄여감.
    int work = 50000;
    while(n > 0 && work > 0){
        int cur_work_size = m[work];
        if(cur_work_size > 0){
            if(n >= cur_work_size){ // 모두 1시간씩 줄일 수 있음
                n -= cur_work_size;
                m[work-1] += cur_work_size;
                m[work] = 0;
            }
            else{ // 모두 1시간씩 줄일 수 없음, break;
                m[work-1] += n;
                m[work] -= n;
                n = 0;
                break;
            }
        } 
        work--;
    }
    
    ll answer = 0;
    for(auto &[key, value] : m){
        if(value == 0) continue;
        answer += (ll)key * (ll)key * (ll)value;
    }
    return answer;
}