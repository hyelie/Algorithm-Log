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

void solve(){
	double x1, y1, r1, x2, y2, r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	double sum = (r1 + r2) * (r1 + r2);
	double sub = (r1 - r2) * (r1 - r2);

	/*int num;
	if(dist == 0 && r1 == r2) num = -1;
	else if(dist > sum) num = 0;
	else if(dist == sum) num = 1;
	else if(sub < dist && dist < sum) num = 2;
	else if(sub == dist) num = 1;
	else num = 0;*/

	int num;
	if(dist == 0 && r1 == r2) num = -1;
	else if(sub < dist && dist < sum) num = 2;
	else if(dist == sum || dist == sub) num = 1;
	else num = 0;

	cout<<num<<'\n';
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int T; cin>>T;
	while(T--){
		solve();
	}

	//////////////////////

	return 0;
}