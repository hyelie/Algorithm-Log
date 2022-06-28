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

void gridCompress(vector<int> &arr){
    vector<int> temp(arr.size());
    for(int i = 0; i<arr.size(); i++){
        temp[i] = arr[i];
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(int i = 0; i<arr.size(); i++){
    	arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    }
}


void gridCompress2(vector<int> &arr){
	set<int> temp;
	for(int i = 0; i<arr.size(); i++){
		temp.insert(arr[i]);
	}

	int i = 0;
   	map<int, int> mapper;
	for(int elem : temp){
		mapper[elem] = i++;
	}

	for(int i = 0; i<arr.size(); i++){
    	arr[i] = mapper[arr[i]];
    }
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below

	int N; cin>>N;vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin>>v[i];
	}

	gridCompress2(v);

	for(int i : v) cout<<i<<' ';
	




	//////////////////////

	return 0;
}