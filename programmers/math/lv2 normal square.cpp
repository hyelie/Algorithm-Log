// 멀쩡한 사각형

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

long long solution(int w,int h) {
    if(w < h) swap(w, h); // w가 더 크게.
    
    ll answer = (ll)w * h;
    for(ll i = 1; i<=h; i++){
        answer -= (ll)ceil((ld)w * i/h) - (ll)floor((ld)w * (i-1)/h);
    }

    return answer;
}