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

int main(void) {
	//cin.tie(0);
	//cout.tie(0);
	//std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	vector<int> arr(N);

	int maxval = -9999, minval = 9999;
	vector<int> shows(8001);
	for(int i= 0; i<N; i++){
		cin>>arr[i];
		shows[arr[i] + 4000]++;
		maxval=  max(maxval, arr[i]);
		minval = min(minval, arr[i]);
	}

	sort(arr.begin(), arr.end());
	
	cout<<(int)round((double)accumulate(arr.begin(), arr.end(), 0) / N)<<'\n';
	cout<<arr[N/2]<<'\n';
	
	int modeidx = max_element(shows.begin(), shows.end()) - shows.begin();
	int cnt = 0;
	for(int i = 0; i<=8000; i++){
		if(shows[i] == shows[modeidx]){
			cnt++;
			if(cnt == 2){
				cout<<i - 4000<<'\n';
				break;
			}
		}
	}
	if(cnt == 1) cout<<modeidx - 4000<<'\n';
	cout<<maxval - minval<<'\n';
	

	//////////////////////

	return 0;
}