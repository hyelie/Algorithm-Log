#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	ll N; cin>>N;
	int answer = 0, sum = 1;

	while(1){
		answer++;
		if(N<=sum) break;
		sum += 6 * answer;


		
	}

	cout<<answer;
	return 0;
}
/*
1 : 변 1개 - 1
2 : 변마다 2개 - 6
3 : 변마다 3개 - 12
4 : 변마다 4개 - 18
그러면 변이 6개니까 1단계 올라갈 떄마다 개수가 6씩 커짐
*/