// 입국심사

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll isEnough(vector<int> times, ll t){
    ll cnt = 0;
    for(int i : times){
        cnt += (ll)t/(ll)i;
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    ll l = 1L, r = (ll)(*max_element(times.begin(), times.end())) * n, mid;
    
    while(l < r){
        mid = (l+r)/2;
        ll pass_num = isEnough(times, mid);
        if(isEnough(times, mid) < n) l = mid+1;
        else{
            r = mid;
        }
    }
    
    return l;
}