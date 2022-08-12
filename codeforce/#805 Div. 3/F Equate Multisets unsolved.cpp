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

void solve(){
	
}

/*
4 24 5 2 -> 1 3 5 1
4 1 6 11 -> 1 1 3 11

2로 떨어지는 건 2로 나누기
최대한
1 1 3 5
1 1 3 11
YES

그러면 결국 1을 제외한 홀수만 문제가 됨

1 4 17 -> 1 1 17
4 5 31 -> 1 5 31
NO

4 7 10 13 14  -> 1 7 7 13 5
2 14 14 26 42 -> 1 7 7 13 21
YES

2 2 4 4 4	   -> 1 1 1 1 1
28 46 62 71 98 -> 7 23 31 71 49
YES

1 2 10 16 64 80   -> 1 1 5 1 1 5
20 43 60 74 85 99 -> 5 43 15 37 85 99
42
21
10
5
2
85는 21, 5가 될 수 있음
43은 21, 5가 될 수 있음
15는 7, 3이 될 수 있음
31은 15, 7, 3이 될 수 있음

1 1 3 7 15
1 1 5 15 31 이것만 해결할 수 있다면.....

//////////
am[i] : value i 갯수라 두고,
바로 위 로직처럼 홀수를 만들 수 있는 경우의 수를 am에서 뺌. 만약 하나라도 0보다 크면 false -> 이러면 암돼
아.. 모르겠다!
5와 85
((((10) * 2 + 1) * 2) * 2  + 1= 85
01010101
101

a에 1이 더 많다 -> 문제없음. 그냥 b를 나눠가기만 하면 됨

5 17
27 85

*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}