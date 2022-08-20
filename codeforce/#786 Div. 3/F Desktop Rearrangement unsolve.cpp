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
vector<string> icons; // * : icon, . : empty
int n, m, q; 
int num_icons = 0;

int count_icons(){
	int result = 0;
	int cnt = num_icons;
	for(int c = 0; c<m; c++){
		for(int r = 0; r<n; r++){
			if(icons[r][c] == '*') result++;
			cnt--;
			if(cnt == 0) return result;
		}
	}
}

void solve(){
	cin>>n>>m>>q;
	icons.resize(n);
	for(int i = 0; i<n; i++) cin>>icons[i];
	for(int r = 0; r<n; r++){
		for(int c= 0 ;c<m; c++){
			if(icons[r][c] == '*') num_icons++;
		}
	}

	int xi, yi;
	while(q--){
		cin>>xi>>yi;
		xi--; yi--;

		if(icons[xi][yi] == '*'){
			num_icons--;
			icons[xi][yi] = '.';
		}
		else{
			 num_icons++;
			 icons[xi][yi] = '*';
		}

		int num_icons_in_good = count_icons();
		cout<<num_icons - num_icons_in_good<<'\n';
	}

}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	solve();
	

	return 0;
}