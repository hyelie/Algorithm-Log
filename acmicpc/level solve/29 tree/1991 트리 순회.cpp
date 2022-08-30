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

int N;
vector<pii> edges;

int char2int(char c){
	return c - 'A';
}

void preorder(int cur){
	cout<<(char)(cur + 'A');
	int leftc = edges[cur].first, rightc = edges[cur].second;
	if(leftc != -19){
		preorder(leftc);
	}
	if(rightc != -19){
		preorder(rightc);
	}
}

void inorder(int cur){
	int leftc = edges[cur].first, rightc = edges[cur].second;
	if(leftc != -19){
		inorder(leftc);
	}
	cout<<(char)(cur + 'A');
	if(rightc != -19){
		inorder(rightc);
	}
}

void postorder(int cur){
	int leftc = edges[cur].first, rightc = edges[cur].second;
	if(leftc != -19){
		postorder(leftc);
	}
	if(rightc != -19){
		postorder(rightc);
	}
	cout<<(char)(cur + 'A');
}

void solve(){
	cin>>N;
	edges.resize(N+1);
	char parent, leftc, rightc;
	for(int i = 0; i<N; i++){
		cin>>parent>>leftc>>rightc;
		edges[char2int(parent)] = {char2int(leftc), char2int(rightc)};
	}

	preorder(char2int('A'));
	cout<<endl;
	inorder(char2int('A'));
	cout<<endl;
	postorder(char2int('A'));
}

//////////////////////

int main(void) {
	// cin.tie(0);
	// cout.tie(0);
	// std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}