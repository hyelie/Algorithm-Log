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

/*
34
9889

999

15
96

1. 일단 최소 자리수를 만들기 위해 가능한 모든 자리를 9로 만들고, 이 수의 자리수를 Q라고 하자. - N + 9 > 9Q >= N이다.
- N과 9Q가 같은 경우, 그대로 palindrome (모든 수가 9)
- Q가 N보다 큰 경우, 나머지를 R이라고 하자. (9Q - N)
- R을 palindrome 형식으로 배분할 수 있는 경우를 찾으면 된다.
  - Q가 짝수면 2개의 숫자에서 하나씩 빼야 한다. 이 경우 R이 홀수면 Q+1이 답, R이 짝수면 Q가 답.
  - Q가 홀수면 하나의 숫자에서 R을 빼면 된다. 이 경우 Q가 답.
*/

int solve(){
	int N; cin>>N;

    int Q = N/9 + (N%9 > 0), R = 9*Q - N;

    if(Q & 1) return Q;
    return Q + (R & 1);
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	cout<<solve();

	return 0;
}