#include <string>
#include <vector>

typedef long long ll;
ll MOD = 1234567;
using namespace std;

long long solution(int n) {
    vector<ll> v(n+1, 0);
    v[0] = 0; v[1] = 1, v[2] = 2;
    ll answer = 0;
    for(int i = 3; i<=n; i++){
        v[i] = (v[i-1] % MOD + v[i-2] % MOD) % MOD;
    }
    
    
    return v[n];
}



// 1 + (n-1)!/(n-2)!*1 + (n-2)!/(n-4)!*2!
// i번째 수 : 1 + sigma(i = 1 to n) (n-i)!/((n-2i)!*i!)
// 근데 그냥 피보나치임
// i-1번째 칸에서 1칸을 더 가는 방법 + i-2번째 칸에서 2칸을 1번 더 가는 방법 = i번째 칸을 가는 방법임.