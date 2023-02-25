#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

long long solution(int k, int d) {
    long long answer = 0;
    ll dsquare = (ll) d * (ll)d;
    for(ll i = 0; i<=d; i += k){
        answer += ((ll)sqrt(dsquare - i * i) / k) + 1;
    }
    return answer;
}
/*
(a^2 + b^2) * k^2 <= d^2인 a, b의 개수

y가 0, k, 2k, 3k, ... d/k 일 때 x좌표
d/k, sqrt(d*d-k*k) / k, sqrt(d*d - 2k*2k) / k

sqrt(d*d/k*k - n*n)


4
1, 1
0, 0
0, 1
1, 0
2, 0
0, 2
*/