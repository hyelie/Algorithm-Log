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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

void solve(){
	int n, k; cin>>n>>k;
	string s; cin>>s;
}

// op : string s에 있는 어떤 char c에 대해 c-1을 함
// k번 이하의 operartion으로 찾을 수 있는 제일 앞에 있는 사전순 낱말

/*
gndcafb
5.
abcedfghijklmnopqrstuvwxyz
3 10 9

제일 앞에서부터 차례대로 해 가면 되는 것 아닌가 ?
제일 앞의 문자 c를 c-'a',
min(26, k)번 줄임. 
c부터 c-k
a부터 a+k까지 char를 map에 넣고, value는 




*/

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}