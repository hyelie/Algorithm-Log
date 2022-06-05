// 3 x n 타일링

#include <string>
#include <numeric>
#include <vector>

using namespace std;
typedef long long ll;
int MOD = 1000000007;

int solution(int n) {
    if(n & 1) return 0;
    vector<ll> v(n+1, 0);
    v[0] = 1L;
    v[2] = 3L;
    
    for(int i = 4; i<=n; i += 2){
        for(int j = 0 ; j<=i-4; j += 2){
            v[i] += v[j] * 2;
        }
        v[i] += 3 * v[i-2];
        v[i] %= MOD;
    }
    
    return (int)v[n];
}