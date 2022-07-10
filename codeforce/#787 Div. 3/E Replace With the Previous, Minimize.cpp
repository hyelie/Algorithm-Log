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
	
	map<char, char> m;
	for(int i = 0; i<s.length(); i++){
		if(m.find(s[i]) != m.end()) continue; // already exist
		
		vector<char> desc_chars;
		char final_char = max((int)s[i] - k, (int)'a');
		for(char c = s[i]; c > 'a'; c--){
			if(m.find(c) == m.end()){
				k--;
				desc_chars.push_back(c);
				if(k == 0) break;
			} else{
				final_char = m[c];
				break;
			}
		}
		for(char c : desc_chars){
			m[c] = final_char;
		}

		if(k == 0) break;
	}

	for(int i = 0; i<s.length(); i++){
		if(m.find(s[i]) != m.end()) s[i] = m[s[i]];
	}
	cout<<s<<'\n';
}

// op : string s에 있는 어떤 char c에 대해 c-1을 함
// k번 이하의 operartion으로 찾을 수 있는 제일 앞에 있는 사전순 낱말

/*
gndcafb
5.
abcdedfghijklmnopqrstuvwxyz
3 10 9

제일 앞에서부터 차례대로 해 가면 되는 것 아닌가 ?
제일 앞의 문자 c를 min(c-'a', k)번 줄임
k -= c-'a'
c부터 c-k까지 char를 map에 넣고, value는 c-k

다음 문자가 map에 있으면 pass, 없으면 같은 logic 진행

ekyv
akyv
aayv

map
bcdefghijk

k
9

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