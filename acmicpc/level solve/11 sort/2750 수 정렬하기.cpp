#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++){
		cin>>arr[i];
	}

	for(int i = 1; i<N; i++){
		int maxval = arr[i];
		int j;
		for(j = i-1; j>=0 && arr[j] > maxval; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = maxval;
	}
	
	for(int i : arr) cout<<i<<'\n';

	//////////////////////

	return 0;
}