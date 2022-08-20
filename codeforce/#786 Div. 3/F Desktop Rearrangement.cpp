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
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

////////////////////// write your code below
// * : icon, . : empty

void solve(){
	int n, m, q; cin>>n>>m>>q;
	
	vector<string> strs(n);
	// desktop : 전체
	int num_icons = 0;
	for(int i = 0; i<n; i++){
		cin>>strs[i];
		for(int c= 0 ;c<m; c++){
			if(strs[i][c] == '*') num_icons++;
		}
	}

	string desktop = "";
	for(int c = 0; c<m; c++){
		for(int r = 0; r<n; r++){
			desktop += (strs[r][c]);
		}
	}

	int num_empty = 0; // 0부터 채워야 할 icon 개수까지 empty 개수
	for(int i = 0; i<num_icons; i++){
		if(desktop[i] == '.') num_empty++;
	}

	int xi, yi;
	while(q--){
		cin>>xi>>yi;
		int index = (xi - 1) + (yi - 1) * n;
		
		if(index >= num_icons){ // 바깥쪽인 경우
			if(desktop[index] == '.'){
				desktop[index] = '*';			// *이 늘어난 경우.
				if(desktop[num_icons] == '.'){ 	// 추가될 것이 .이면 empty++
					num_empty++;
				}
				num_icons++;
			}
			else{ // == '*'
				desktop[index] = '.';			
				num_icons--;					// *이 줄어든 경우
				if(desktop[num_icons] == '.'){	// 원래의 마지막 것이 .이었다면 empty--
					num_empty--;
				}	
			}
		}
		else{ // 안쪽에 있는 경우
			if(desktop[index] == '.'){
				desktop[index] = '*';			// *이 늘어난 경우.
				if(desktop[num_icons] == '.'){	// 추가될 것이 .이면 empty++
					num_empty++;
				}
				num_icons++; 
				num_empty--;					// 원래 있던 empty가 사라졌음
			}
			else{ // == '*'
				desktop[index] = '.';
				num_icons--;					// *이 줄어든 경우
				if(desktop[num_icons] == '.'){	// 원래의 마지막 것이 .이었다면 empty--
					num_empty--;
				}	
				num_empty++;					// 원래 있던 *이 사라졌음
			}
		}

		cout<<num_empty<<'\n';
	}
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	solve();
	

	return 0;
}