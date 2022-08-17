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
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++) cin>>arr[i];
	sort(arr.begin(), arr.end(), less<int>());
	int x; cin>>x;

	int s = 0, e = n-1, answer = 0, cur_sum;
	while(s < e){
		cur_sum = arr[s] + arr[e];
		if(cur_sum == x){
			answer++;
			s++; e--;
		}
		else if(cur_sum < x){
			s++;
		}	
		else{ // cur_sum > x
			e--;
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