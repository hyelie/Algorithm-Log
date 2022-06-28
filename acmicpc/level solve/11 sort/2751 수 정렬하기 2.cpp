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

void merge(vector<int>& arr, int begin, int end){
	int mid = (begin + end) / 2;
	int leftarrlen = mid - begin + 1;
	int rightarrlen = end - mid;

	vector<int> leftarr(leftarrlen), rightarr(rightarrlen);

	for(int i = begin; i <= mid; i++){
		leftarr[i - begin] = arr[i];
	}
	for(int i = mid+1; i <= end; i++){
		rightarr[i - mid -1] = arr[i];
	}

	int leftidx = 0, rightidx = 0, arridx = begin;
	while(leftidx < leftarrlen && rightidx < rightarrlen){
		if(leftarr[leftidx] <= rightarr[rightidx]){
			arr[arridx++] = leftarr[leftidx++];
		} else{
			arr[arridx++] = rightarr[rightidx++];
		}
	}
	
	while(leftidx < leftarrlen){
		arr[arridx++] = leftarr[leftidx++];
	}
	while(rightidx < rightarrlen){
		arr[arridx++] = rightarr[rightidx++];
	}
	return;
}

void merge_sort(vector<int>& arr, int begin, int end){
	if(begin >= end) return;
	int mid = (begin + end) / 2;
	merge_sort(arr, begin, mid);
	merge_sort(arr, mid+1, end);
	merge(arr, begin, end);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int N, input; cin>>N;
	vector<int> arr(N);
	for(int i = 0; i<N; i++){
		cin>>arr[i];
	}
	
	merge_sort(arr, 0, N-1);

	for(int i : arr){
		cout<<i<<'\n';
	}
	
	

	//////////////////////

	return 0;
}