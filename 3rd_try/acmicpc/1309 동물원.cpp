#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#include <cmath>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below

int MOD = 9901;

void solve(){
	int N; cin>>N;

    // dp init
    N--;
    int xx = 1, ox = 1, xo = 1;
    // xx: 둘 다 안 놓는 경우
    // ox: 왼쪽에만 놓는 경우
    // oo: 오른쪽에만 놓는 경우

    // 현재 state: 이전 state가 어떻게 놓였냐에만 의존함.


    while(N--){
        int tempxx = xx, tempox = ox, tempxo = xo;
        xx = (tempxx + tempox + tempxo) % MOD;
        ox = (tempxx + tempxo) % MOD;
        xo = (tempxx + tempox) % MOD;
    }

    cout<<(xx+ox+xo) % MOD;


}

/*
dp[i][j] : i, j에 놓았을 때 경우의 수
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	// comment when submit
	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}