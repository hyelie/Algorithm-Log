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

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	int N; cin>>N;

	int answer = -1, possible_num = N/5;

	while(possible_num >= 0){
		int left = N-possible_num*5;
		if(left % 3 == 0){
			answer = left / 3 + possible_num;
			break;
		}
		possible_num--;
		
	}

	cout<<answer;

	return 0;
}