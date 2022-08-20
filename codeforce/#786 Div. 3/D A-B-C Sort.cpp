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
string yes = "YES\n", no="NO\n";

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++) cin>>arr[i];

	vector<int> c;
	int type = arr.size() % 2;
	for(int i = 0; i<n; i++){
		c.push_back(arr[i]);
		if(c.size() % 2 == type && c.size() > type + 1){
			if(c[c.size() - 2] > c[c.size()-1]){
				swap(c[c.size() - 2], c[c.size() - 1]);
			}
		}
	}

	for(int i = 1; i<n; i++){
		if(c[i-1] > c[i]){
			cout<<no;
			return;
		}
	}
	cout<<yes;

	/*int type = arr.size() % 2;
	for(int i = type; i<n; i += 2){
		if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
	}

	for(int i = 1; i<n; i++){
		if(arr[i-1] > arr[i]){
			cout<<no;
			return;
		}
	}
	cout<<yes;*/

	

	/*
	b, c는 빈상태
	1 : a가 비지 않았으면 a.back()을 뽑아서 b의 middle에 넣음. b가 홀수길이면 b의 왼쪽 가운데, 또는 오른쪽 가운데 선택해서 올림
	-> a.front()는 맨 마지막에 들어감
	2 : b가 빌때까지 b의 middle을 골라서 c의 end에 넣음. b가 짝수길이면 뭘 골라도 상관없음
	a가 짝수개 -> a[1], a[3]는 앞뒤 맘대로 넣을 수 있음
	a가 홀수개 -> a[0], a[2]이 앞뒤 맘대로 들어감

	a b c d e
	e
	d e 		 									e d
	d c e		 									e c d
	d c b e				d b c e 					e b c d 		e c b d
	d c a b e			d b a c e					e b a c d		e c a b d

	빼면...
	a
	a b												a c	
	a b c											a c b
	a b c d				a b c e						a c b d			a c b e
	a b c d e			a b c e d					a c b d e		a c b e d
	즉... a가 홀수면 [1, 2], [3, 4], ...를 교체 가능

	a가 짝수면 [0, 1], [2, 3], ...을 교체 가능
	a b c d
	d
	c d												d c
	c b d											d b c
	c a b d			c b a d 						d a b c		d b a c

	빼면
	a												b
	a b												b a
	a b c			a b d							b a c		b a d
	a b c d			a b d c

	*/
}

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