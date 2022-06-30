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
	
}

/*
각각 k, d에 대해 줄이고, 줄인 이후에 몇 개의 군집이 남아있는지 계산하는 문제임

set에는 기차가 시작하는 index를 두고,
d, k가 입력되어서 carriage 속도를 감속시켜야 할 때 (k는 기차 index, d는 감속량)
j <= k인 maximal j를 찾는다. 그리고 aj > ak라면 ak부터 새 기차가 시작된다. 

어떤 수가 줄면, 그 수부터 끝까지 lower bound(그 수보다 크거나 같은 수 중 제일 작은 수)를 찾아서
바뀐 수부터 그 수의 upper bound까지 전부 바뀐 수로 바뀌어야 함

숫자들의 set을 보관한다면, 그 set size가 답임.

O(m nlogn)

set : 기차가 시작하는 index를 담아 둠
d가 감속되었을 때, 그것보다 작은 속도 중 maximal을 찾음 - 이 때 group의 선두라면 그룹 자체를 지워야 하고, 그렇지 않으면 그 그룹 값은 내비둬야 할 것.
'다음 노드의 좌표를 알아야 함' - 다음 노드는 set으로 찾을 수 있음
k보다 큰 j에 대해, ak < aj인 j의 값은 지우고, ak > aj인 j의 값이 나오면 stop
k <= j에 대해, ak > aj
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