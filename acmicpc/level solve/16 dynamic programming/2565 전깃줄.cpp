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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	vector<pii> arr(n);
	for(int i = 0; i<n; i++) cin>>arr[i].first>>arr[i].second;

	sort(arr.begin(), arr.end());

	vector<int> lis(n, 1);
	for(int i = 1; i<n; i++){
		for(int j = 0; j<i; j++){
			if(arr[j].second < arr[i].second){
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}

	
	cout<<n - *max_element(lis.begin(), lis.end());
	


	//////////////////////

	return 0;
}