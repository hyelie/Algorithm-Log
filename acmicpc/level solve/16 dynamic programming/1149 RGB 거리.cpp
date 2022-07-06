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

void solve(){
	
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int n; cin>>n;

	vector<int> houses(3); // house[i] : i번째에 house를 골랐을 때 최솟값
	cin>>houses[0]>>houses[1]>>houses[2];
	n--;

	int a, b, c, b0, b1, b2;
	while(n--){
		cin>>a>>b>>c;
		b0 = houses[0]; b1 = houses[1]; b2 = houses[2];
		
		
		houses[2] = min(b0, b1) + c;
		houses[1] = min(b0, b2) + b;
		houses[0] = min(b1, b2) + a;
	}
	cout<<min(houses[0], min(houses[1], houses[2]));



	//////////////////////

	return 0;
}