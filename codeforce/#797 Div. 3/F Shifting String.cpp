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

int gcd(int a, int b){
	int r;
	if(b > a) return gcd(b, a);
	while(b != 0){
		r = (int)a % b;
		a = b;
		b = r;
	}
	return a;
}

ll lcm(int a, int b){
	return (ll)a * b / gcd(a, b);
}

// abcdefab와 같이 일반적인 경우 -> 길이를 리턴
// abcabc와 같이 반복되는 경우 -> 그 cycle을 찾아 리턴
int minCycle(string s){
	int i;
	for(i = 1; i<s.length(); i++){
		string f = s.substr(i), e = s.substr(0, i);
		if(f + e == s) break;
	}
	return i;
}

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	vector<int> arr(n);
	vector<bool> visited(n, false);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		arr[i]--;
	}

	ll answer = 1;
	for(int i = 0; i<n; i++){
		if(visited[i]) continue;
		string loop = "";
		while(!visited[i]){
			loop += s[i];
			visited[i] = true;
			i = arr[i];
		}
		int min_cycle = minCycle(loop);
		answer = lcm(answer, min_cycle);
	}

	cout<<answer<<'\n';
}

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