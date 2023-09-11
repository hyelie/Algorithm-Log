534#define _USE_MATH_DEFINES 
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
	int N; cin>>N;
	string name; cin>>name;
	vector<string> garbages(N);
	for(int i = 0; i<N; i++) cin>>garbages[i];

	int answer = 0;
	for(string garbage : garbages){
		int gap = 0;
		while(1){
			int sublen = name.length() + gap * ((int)name.length()-1); // gap일 때 문자열 길이
			if(sublen > garbage.length()) break;

			bool isMatch = true;
			for(int i = 0; i<garbage.length() - sublen + 1; i++){ // i부터 시작, 가능한 모든 시작점 검사
				isMatch = true;
				for(int k = 0; k<name.length(); k++){
					if(name[k] != garbage[i + (gap+1) * k]){
						isMatch = false;
						break;
					}
				}
				if(isMatch){
					answer++;
					break;
				}
			}

			if(isMatch) break;
			gap++;
			
		}
	}
	
	cout<<answer;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}