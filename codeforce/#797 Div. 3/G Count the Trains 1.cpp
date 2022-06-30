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

// arr는 내림차순 정렬, target 이상의 값의 index를 찾음
int lb(vector<int> arr, int start, int end, int target){
	int mid;
	while(start < end){
		int mid = (start + end) / 2;
		if(arr[mid] == target){ // mid와 target이 같음 -> target은 mid~end 사이에 있을 것.
			start = mid;
		}
		else if(arr[mid] > target){ // mid가 target보다 큼 -> target은 mid~end 사이에 있을 것. start = mid
			start = mid + 1;
		}
		else{ // mid가 target보다 작음 -> target은 start ~ mid 사이에 있을 것. end = mid
			end = mid - 1;
		}
	}
	return start;
}

void print(vector<int> carriage){
	vector<int> result(carriage.begin(), carriage.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	cout<<result.size()<<' ';
}

void solve(){
	string empty;
	getline(cin, empty);
	int n, m; cin>>n>>m;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin>>a[i];
	vector<int> carriage;
	for(int i = 0; i<n; i++){
		int cur_i = i;
		carriage.push_back(a[cur_i]);
		while(i+1 < n && a[cur_i] < a[i+1]){
			i++;
			carriage.push_back(a[cur_i]);
		}
	}

	// for(int i : carriage) cout<<i<<'\n';

	set<int> sets;
	for(int i : carriage) sets.insert(i);

	int k, d;
	while(m--){
		cin>>k>>d;
		k--;
		a[k] -= d;
		if(a[k] > carriage[k]){
			//print(carriage);
			cout<<sets.size()<<' ';
			continue;
		}

		//int lbidx = lb(carriage, k, n-1, a[k]);

		// 이 단계가 lb로 해결되어야 하고
		int lbidx;
		for(lbidx = n-1; lbidx>=k; lbidx--){
			if(a[k] <= carriage[lbidx]) break;
		}

		for(int i = k; i<=lbidx; i++){
			sets.erase(carriage[i]);
			carriage[i] = a[k];
		}

		if(k > 0) sets.insert(carriage[k-1]);
		if(lbidx < n-1) sets.insert(carriage[lbidx + 1]);
		sets.insert(carriage[k]);



		//print(carriage);
		cout<<sets.size()<<' ';
	}
	cout<<'\n';
}

/*
각각 k, d에 대해 줄이고, 줄인 이후에 몇 개의 군집이 남아있는지 계산하는 문제임

어떤 수가 줄면, 그 수부터 끝까지 lower bound(그 수보다 크거나 같은 수 중 제일 작은 수)를 찾아서
바뀐 수부터 그 수의 upper bound까지 전부 바뀐 수로 바뀌어야 함

숫자들의 set을 보관한다면, 그 set size가 답임.

O(m nlogn)
*/

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