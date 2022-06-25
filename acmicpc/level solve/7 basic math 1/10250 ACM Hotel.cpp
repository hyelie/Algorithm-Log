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
void solve(){
	int H, W, N;
	cin>>H>>W>>N;

	int floor = (N-1)%H + 1;
	int room = (N-1)/H + 1;
	string sfloor = to_string(floor), sroom = to_string(room);
	if(room < 10) sroom = "0" + sroom;
	cout<<sfloor + sroom<<'\n';
	return;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while(t--){
		solve();
	}


	return 0;
}