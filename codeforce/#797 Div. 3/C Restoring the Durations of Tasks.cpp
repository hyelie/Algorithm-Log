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
	int n; cin>>n;
	vector<int> s(n), f(n);
	for(int i = 0; i<n; i++){
		cin>>s[i];
	}
	for(int i = 0; i<n; i++){
		cin>>f[i];
	}

	int left = 0, right = 0, start_time;
	while(left < n){
		while(right < n -1 && f[right]> s[right + 1]){
			right++;
		}
		if(left == right){
			cout<<f[left] - s[left]<<' ';
			left++; right++;
		} else{
			start_time = s[left];
			while(left <= right){
				cout<<f[left] - start_time<<' ';
				start_time = f[left];
				left++;
			}
			right = left;
		}
	}
	cout<<'\n';
	
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

/*


*/