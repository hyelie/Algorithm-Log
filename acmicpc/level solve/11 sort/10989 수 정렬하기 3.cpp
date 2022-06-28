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
	
	int N, input; cin>>N;
	vector<int> arr(10001);
	for(int i = 0; i<N; i++){
		cin>>input;
		arr[input]++;
	}
	
	for(int i = 1; i<=10000; i++){
		while(arr[i]--){
			cout<<i<<'\n';
		}
	}

	//////////////////////

	return 0;
}