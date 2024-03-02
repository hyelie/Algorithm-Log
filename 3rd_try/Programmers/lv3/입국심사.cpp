#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool Can_Pass(ll time, vector<int> &times, int n){ // time 시간 내에 모두 심사받을 수 있는지
    ll sum = 0; // 심사받을 수 있는 인원
    for(int t : times){
        sum += (time / (ll) t);
    }
    return sum >= n;
}

ll solution(int n, vector<int> times) {
    ll start = 0, end = (ll)(*max_element(times.begin(), times.end())) * (ll)n, mid;
    
    while(start < end){
        mid = start + (end - start) / 2;
        
        if(Can_Pass(mid, times, n)){ // 심사할 수 있으면 시간 더 줄일 수 있음
            end = mid;
        }
        else start = mid + 1;
    }
    // return : can_pass를 만족하는 제일 작은 값
    
    return end;
}