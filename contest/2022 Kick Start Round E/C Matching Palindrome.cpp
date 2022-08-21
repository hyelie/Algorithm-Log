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
	int N; cin>>N;
	string P; cin>>P; // p : palindrome
	// Q도 palindrome, PQ도 palindrome, shortest Q 찾기
	// P의 sub가 palindrome + 그게 전체 반복
	/*
	aababaa
	cdc cdc cdc cdc cdc

	abac caba
	
	*/

	for(int len = 1; len <= N/2; len++){
		string str = P.substr(0, len);
		if(N % str.length() != 0) continue;
		bool flag = true;
		for(int sidx = 1; sidx < N / str.length(); sidx++){
			if(str != P.substr(sidx * len, len)){
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout<<str;
			return;
		}
	}
	cout<<P;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	for(int i =1; i<=t; i++){
		cout<<"Case #"<<i<<": "; solve(); cout<<'\n';
	}

	return 0;
}
