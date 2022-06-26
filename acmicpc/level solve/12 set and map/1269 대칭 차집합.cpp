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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below

	int An, Bn, sum;
	cin>>An>>Bn;
	sum = An + Bn;

	set<int> aset;
	int input;
	while(An--){
		cin>>input;
		aset.insert(input);
	}

	int num_subset = 0;
	while(Bn--){
		cin>>input;
		if(aset.find(input) != aset.end()) num_subset++;
	}

	cout<<sum - 2 * num_subset;

	//////////////////////

	return 0;
}