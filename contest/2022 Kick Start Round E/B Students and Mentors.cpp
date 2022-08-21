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

int upper_bound(vector<pii> &v, int target)
{
	int mid, start = 0, end = v.size();
	while (start < end) 
	{
		mid = (start + end) / 2; 
		if (v[mid].first > target) // 중간값이 target보다 큰 경우 해당 index까지 end를 당김.
			end = mid;
		else start = mid + 1; // 중간값이 target보다 작으면 mid+1까지 start를 당김.
	}
	return end;
}

bool cmp(pii &a, pii &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

void solve(){
	int N; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++) cin>>arr[i];
	vector<pii> sarr(N);
	for(int i = 0; i<N; i++) sarr[i] = {arr[i], i}; // .first : value, .second : index
	sort(sarr.begin(), sarr.end(), cmp);

	vector<int> answer(N);
	for(int i = 0; i<N; i++){
		int index = upper_bound(sarr, arr[i] * 2)-1; // arr[i]*2의 ub index - 1

		if(sarr[index].second == i){ // 자기 자신이 나온 경우
			index--;
		}
		if(index < 0){
			answer[i] = -1;
		}
		else{
			answer[i] = sarr[index].first;
		}
	}

	for(int elem : answer) cout<<elem<<' ';


	/*
	각 student는 다른 학생 중 1명의 멘토를 가지며,
	여러 명의 멘토가 될 수 있다.
	arr[i] : 실력.
	j가 i의 mentor가 되려면 arr[j] <= 2*arr[i]

	bsearch ?인 것 같은데, 자기 자신을 고르는 경우를 어떻게 제할 거냐....
	2배의 upper bound 구하고 ub -1하면 될 듯?

	일반적인 경우는 그렇게 구할 수 있겠지만
	1) 자기 자신이 나오는 경우 - up 결과가 begin이 나오는 경우는 없음
	2) 없는 경우
	를 잘 제해야 할 것 같은데


	1500 1900 2000
	*/



}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	for(int i =1; i<=t; i++){
		cout<<"Case #"<<i<<": "; solve(); cout<<'\n';
	}

	return 0;
}
