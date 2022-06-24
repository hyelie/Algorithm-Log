#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve(){
	int n, s; cin>>n>>s;
	vector<int> v(n); cin>>v[0];
	for(int i = 1; i<n; i++){
		cin>>v[i];
		v[i] += v[i-1];
	}

	if(v[n-1] < s){
		cout<<"-1\n";
		return;
	}

	int start = 0, end;
	for(int i = n-1; i>=0; i--){
		if(v[i] == s){
			end = i;
			break;
		}
	}
	int max_len = end - start + 1;


	while(end < n){
		while(end + 1 < n && v[end + 1] == v[end]){ // end는 최대한 오른쪽 끝까지 당김
			end++;
		}

		int ssum = v[end] - (start - 1 < 0 ? 0 : v[start - 1]);
		if(ssum == s){
			max_len = max(max_len, end - start + 1);
			start++;
		}
		else if(ssum < s){ // end를 수가 바뀔 때까지 당기자
			while(end + 1 < n && v[end + 1] == v[end]){
				end++;
			}
			end++;
		} else{ // start를 수가 바뀔 때까지 당기자
			while(start + 1 <= end && v[start] == v[start + 1]){
				start++;
			}
			start++;
		}

		if(start > end){
			end = start;
		}
	}

	// 와.. 부분합이 오름차순 정렬되어 있으니까 l 기준으로 합이 s가 되는 binary search를 적용할 수 있구나
	
	
	cout<<n - max_len<<'\n';
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

// v에는 0과 1만 들어있고, total sum이 s와 같아지는 operation의 최솟값.
// 불가하다면 -1 출력

// psum : s[i] : s[0]부터 s[i]까지 합
// s[i] - s[j-1] : j to i까지 합
// tp 문제인 것 같은데
// s, e 두고

// 1 0 0
// 1 1 1

// 1 1 0
// 1 2 2

// 0 1 0 1 1 1 0 0 1
// 0 1 1 2 3 4 4 4 5


// 1 1 1 1 1 1
// 1 2 3 4 5 6


// 0 0 1 1 0
// 0 0 1 2 0


// 1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
// 1 2 2 2 3 3 3 4 5 5 5 5 5 5 6 7



// 1 0 1 0 0 0
