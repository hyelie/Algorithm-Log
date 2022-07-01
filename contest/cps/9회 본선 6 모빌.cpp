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
typedef pair<ll, ll> pll;

vector<int> v;
int LIMIT = 12;

int cti(char c){
	return LIMIT - 1 - c + 'a';
}

bool condition(int cur_depth){
	bool flag = true;
	int a = v[cti('a')];
	int b = v[cti('b')];
	int c = v[cti('c')];
	int d = v[cti('d')];
	int e = v[cti('e')];
	int f = v[cti('f')];
	int g = v[cti('g')];
	int h = v[cti('h')];
	int i = v[cti('i')];
	int j = v[cti('j')];
	int k = v[cti('k')];
	int l = v[cti('l')];
	if(cur_depth >= 1 && 3 * k != l) flag = false;
	if(cur_depth >= 4 && 3 * j != i + 2 * h) flag = false;
	if(cur_depth >= 6 && f != k + l + 2*g) flag = false;
	if(cur_depth >= 9 && c != d + 2*e) flag = false;
	if(cur_depth >= 9 && c + d + e != f + g + k + l) flag = false;
	if(cur_depth >= 11 && 3*(h + i + j) + a != c + d + e + f + g + k + l + 3 *b) flag = false;
	return flag;
}

void permutate(int cur_depth, int max_depth, vector<int>& candidate, vector<bool>& isUsed){
	if(cur_depth == max_depth){
		// 조건		
		for(int i = 0; i<v.size(); i++){
			cout<<v[v.size()-1-i]<<' ';
		}
		return;
	}

	for(int i = 0; i<max_depth; i++){
		if(!isUsed[i]){
			isUsed[i] = true;
			v[cur_depth] = candidate[i];
			if(condition(cur_depth))
			permutate(cur_depth + 1, max_depth, candidate, isUsed);
			isUsed[i] = false;
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int LIMIT = 12;
	vector<int> v1(LIMIT); v = v1;
	vector<int> candidate(LIMIT); for(int i = 0; i<LIMIT; i++) candidate[i] = i+1;
	vector<bool> isUsed(LIMIT, false);
	permutate(0, LIMIT, candidate, isUsed);
	
	

	//////////////////////

	return 0;
}