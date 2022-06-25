#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;


int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int A, B, C; cin>>A>>B>>C;

	int isZero = (int)A%(int)(C-B) == 0 ? 1 : 0;
	//A + x*B < x*C인 x
	if(C <= B) cout<<"-1";
	else cout<< (int)ceil((double)A/((double)C-B)) + isZero;

	return 0;
}