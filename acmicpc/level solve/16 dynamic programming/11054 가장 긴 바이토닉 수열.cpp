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

vector<int> getLIS(vector<int>& arr){
	vector<int> result(arr.size(), 1);
	for(int i = 1; i<arr.size(); i++){
		for(int j = 0; j<i; j++){
			if(arr[j] < arr[i]){
				result[i] = max(result[i], result[j] + 1);
			}
		}
	}
	return result;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;
	vector<int> arr(n), lis(n, 1);
	for(int i = 0; i<n; i++) cin>>arr[i];

	vector<int> front = getLIS(arr);
	reverse(arr.begin(), arr.end());
	vector<int> back = getLIS(arr);

	int max_val = 1;
	for(int i = 0; i<n; i++){
		/*if(front[i] == 1) front[i] = 0;
		if(back[i] == 1) back[i] = 0;*/
		max_val = max(max_val, front[i] + back[n - i - 1] - 1);
		
	}
	cout<<max_val;
	


	//////////////////////

	return 0;
}