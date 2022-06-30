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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int a, b;
	string s;
	while(1){
		cin>>a>>b;
		if(a == 0 && b == 0) break;
		if(b%a == 0) s = "factor";
		else if(a%b == 0) s = "multiple";
		else s = "neither";
		cout<<s<<'\n';
	}


	//////////////////////

	return 0;
}