#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <iterator>
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
	string empty;
	getline(cin, empty);
	int n, m; cin>>n>>m;
	vector<int> a(n);
	set<int> clusters; // 기차 group의 시작 index. 오름차순 정렬되어 있지만, vector안쓰는 이유는 삭제 연산이 오래 걸려서
	for(int i = 0; i<n; i++){
		cin>>a[i];
		if(clusters.empty() || a[*(clusters.rbegin())] > a[i]) clusters.insert(i);
	}
	
	int k, d;
	for(int i = 0; i<m; i++){
		cin>>k>>d;
		k--;

		a[k] -= d;

		// 만약 set에 k가 있는 경우 -> k는 이미 기차 group의 시작임 -> 아무것도 할 필요 없음
		// 없는 경우 -> k가 속한 group의 군집을 찾아야 함 -> prev(lower_bound()). 
		// 이후, 그 군집의 속도보다 바뀐 속도가 더 작아야 새로운 group을 만들 수 있음

		if(clusters.find(k) == clusters.end()){ // 없는 경우, 그 군집의 value보다 작아야 넣을 수 있음
			set<int>::iterator iter = prev(clusters.lower_bound(k));
			if(a[*iter] > a[k]) clusters.insert(k);
		} // 있는 경우, 아무것도 안 해도 됨


		// TLE 나는 코드
		/*
		// 현 group부터 'group의 속도가 현 group보다 작기 전까지' 반복
		set<int>::iterator iter = clusters.lower_bound(k), next_iter;
		while(1){
			next_iter = next(iter);
			// 끝이거나, k의 value가 더 클 경우까지 계속 지움
			if(next_iter == clusters.end() || a[*next_iter] < a[k]) break;
			clusters.erase(next_iter);
		}*/

		// 현 group부터 'group의 속도가 현 group보다 작기 전까지' 반복
		while(1){
			set<int>::iterator iter = clusters.upper_bound(k);
			// 끝이거나, k의 value가 더 클 경우까지 계속 지움
			if(iter == clusters.end() || a[*iter] < a[k]) break;
			clusters.erase(iter);
		}

		cout<<(int) clusters.size()<<' ';
	}
	cout<<'\n';
}

/*
각각 k, d에 대해 줄이고, 줄인 이후에 몇 개의 군집이 남아있는지 계산하는 문제임

set에는 기차가 시작하는 index를 두고,
k, d가 입력되어서 carriage의 속도를 감속시켜야 할 때 (k는 기차 index, d는 감속량)
set에 존재하는(group의 시작점) k보다 큰 모든 index i에 대해, a[i] >= a[k]라면 i로 시작하는 group은 지워야 한다.
	또한 set은 오름차순 정렬이기에 a[i] < a[k]면 탐색을 그만두어도 된다.

시간복잡도는 O(mlogn)이며, 총 m번 탐색하며, 1번의 탐색에서 이진탐색에 logn이며, 모든 탐색에서 group에 값을 넣어봤자 set의 size는 2n, 따라서 erase하는 최대의 횟수는 2n이다.
즉, 총 m번 탐색, 총 2n번 삭제, 각 탐색에서 이진탐색 logn이니까 O((m+n)logn)이다.
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