#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve(){
	int n; cin>>n;

	int input;
	vector<int> arr(10, 0);
	for(int i = 0 ;i<n;i++){
		cin>>input;
		input %= 10;
		arr[input]++;
	}

	vector<int> v;
	for(int i = 0; i<10; i++){
		int repeat_num = arr[i] <= 2 ? arr[i] : 3; // 그 숫자 개수가 2보다 작으면 그 크기를, 더 크면 3으로
		for(int k = 0; k<repeat_num; k++){
			v.push_back(i);
		}
	}
	
	int vsize = v.size();
	for(int i = 0; i<vsize; i++){
		for(int j = i+1; j<vsize; j++){
			for(int k = j+1; k<vsize; k++){
				if((v[i] + v[j] + v[k]) % 10 == 3){
					cout<<"YES\n";
					return;
				}
			}
		}
	}
	
	cout<<"NO\n";
}

int main(void) {
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
