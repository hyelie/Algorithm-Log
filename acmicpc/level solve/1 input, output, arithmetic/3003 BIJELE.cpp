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

void solve(){
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int object[6] = {1, 1, 2, 2, 2, 8};
	int cur[6];
	for(int i = 0; i<6; i++){
		cin>>cur[i];
		cout<<object[i] - cur[i]<<' ';
	}


	//////////////////////

	return 0;
}