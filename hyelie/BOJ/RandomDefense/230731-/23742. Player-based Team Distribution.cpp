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
vector<int> arr;

void solve(){
	cin>>N;
	arr.resize(N);
	for(int i = 0; i<N; i++) cin>>arr[i];

	ll sum = 0;
	int cnt = 0;
	vector<int> negs;
	for(int i : arr){
		if(i >= 0){
			sum += i;
			cnt++;
		}
		else negs.push_back(i);
	}
	sort(negs.begin(), negs.end(), greater<int>());

	ll negsum = 0;
	for(int neg : negs){
		if(sum * cnt + neg <= (sum + neg) * (cnt + 1)){
			sum += neg;
			cnt++;
		}
		else negsum += neg;
	}

	cout<<sum * cnt + negsum;
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}