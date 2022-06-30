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
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	ll answer = 0;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		answer += arr[i] / k;
		arr[i] %= k;
	}
	
	sort(arr.begin(), arr.end());

	int left = 0, right = n-1;
	while(left < right){
		if(arr[left] + arr[right] >= k){
			answer++;
			left++; right--;
		} else{
			left++;
		}
	}

	// default : 오름차순
	// 정렬되어 있기 때문에 d

	// 0 1 3 3 3 4, k = 5
	// greedy하게 고르면 되는 이유 : a[i]와 a[j]를 어떻게 더해도 2k보다 크거나 같아질 수 없기 때문
	// 따라서 고르기만 하면 됨
	// 만약 greedy하게 고르지 않은 것이 optimal이라고 하면... 
	// 현재 것을 뽑을 수 있는데도 더 안쪽 것을 위해 양보하는 상황임
	// left를 당긴다면 더 큰 수가 오고, right를 당긴다면 더 작은 수가 골라짐
	// left를 당긴다면 -> 그 수는 left보다 더 큼, 그만큼의 남는 수를 낭비하기 때문에 not optimal
	// right를 당긴다면 -> 그 수는 right보다 더 작음, 그만큼의 부족한 수를 cover하기 위해 left를 더 당겨야 함 -> not optimal


	cout<<answer<<'\n';
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