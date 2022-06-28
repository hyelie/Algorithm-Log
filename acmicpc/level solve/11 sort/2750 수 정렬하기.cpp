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

void bubbleSort(vector<int> &arr){
	for(int i = 0; i<N; i++){
		for(int j = i+1; j<N; j++){
			if(arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}
}

void selectionSort(vector<int> &arr){
	for(int i = 0; i<N; i++){
		int minidx = i;
		for(int j = i+1; j<N; j++){
			if(arr[j] < arr[minidx]){
				minidx = j;
			}
		}
		swap(arr[i], arr[minidx]);
	}
}

void insertionSort(vector<int> &arr){
	for(int i = 1; i<N; i++){
		int maxval = arr[i];
		int j;
		for(j = i-1; j>=0 && arr[j] > maxval; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = maxval;
	}
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

	bubbleSort(arr);
	
	for(int i : arr) cout<<i<<'\n';

	//////////////////////

	return 0;
}