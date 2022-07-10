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


/*void solve(){
	int n, k; cin>>n>>k;
	string s; cin>>s;
	
	map<char, char> m; m['a'] = 'a';
	for(int i = 0; i<s.length(); i++){
		if(m.find(s[i]) != m.end()) continue; // already exist
		
		vector<char> desc_chars;
		char final_char = max((int)s[i] - k, (int)'a');
		char final_c = final_char;
		for(char c = s[i]; c >= final_char; c--){
			if(m.find(c) == m.end()){
				desc_chars.push_back(c);
			} else{
				final_char = m[c];
				final_c = c;
				break;
			}
		}

		k -= (s[i] - final_c);


		for(char c : desc_chars){
			m[c] = final_char;
		}

		if(k == 0) break;
	}

	for(int i = 0; i<s.length(); i++){
		if(m.find(s[i]) != m.end()) s[i] = m[s[i]];
	}
	cout<<s<<'\n';
}*/

void solve(){
	int n, k; cin>>n>>k;
	string s; cin>>s;
	
	vector<char> isUsed(26, '0'); // if ith alphabet is unused, isUsed[i] equals '0'
	isUsed[0] = 'a';
	/*for(int i = 0; i<s.length(); i++){
		char cur_char = s[i];
		if(isUsed[cur_char - 'a'] != '0') continue; // already exist
		
		char final_char = max((int)s[i] - k, (int)'a'); // 제일 최소로 올 수 있는 char
		for(char c = cur_char; c >= final_char; c--){
			if(isUsed[c - 'a'] != '0'){ // 만약 이미 계산된 c라면, 해당 c로 final_char를 수정.
				final_char = c; // 여기까지만 당기면 됨
				break;
			}
		}

		k -= (cur_char - final_char); // k 값 수정
		
		for(char c = cur_char; c >= final_char; c--){ // cur_char부터 final_char까지 값 변경
			isUsed[c - 'a'] = (isUsed[final_char - 'a'] == '0' ? final_char : isUsed[final_char - 'a']); // final_char가 unused라면 final_char로, used라면 거기 안에 있는 값으로 set
		}

		if(k <= 0) break;
	}*/ // 해당 코드를 간결하게 줄인 것

	for(int i = 0; i<s.length(); i++){
		char cur_char = s[i];
		if(isUsed[cur_char - 'a'] != '0') continue; // already exist
		
		char final_char = max((int)s[i] - k, (int)'a');

		for(char c = cur_char; c >= final_char; c--){
			if(isUsed[c - 'a'] != '0'){ // unused then edit end point
				final_char = c;
			}
			else{ // used then 
				isUsed[c - 'a'] = (isUsed[final_char - 'a'] == '0' ? final_char : isUsed[final_char - 'a']);
			}
		}
		k -= (cur_char - final_char);

		if(k <= 0) break;
	}

	for(int i = 0; i<s.length(); i++){
		if(isUsed[s[i] - 'a'] != '0') s[i] = isUsed[s[i] - 'a'];
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