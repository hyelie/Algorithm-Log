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
	string s; cin>>s;
	int zeroidx = s.length(), oneidx = -1;
	for(int i = 0; i<s.length(); i++){
		if(s[i] == '0'){
			zeroidx = i;
			break;
		}
	} // 제일 앞에 있는 zero
	for(int i = s.length()-1; i>=0; i--){
		if(s[i] == '1'){
			oneidx = i;
			break;
		}
	} // 제일 뒤에 있는 one

	int answer;
	if(zeroidx == s.length() && oneidx == -1) answer = s.length(); // 둘다 찾지 못하면 전부 ?
	//else if(zeroidx < oneidx) answer = 1;	// 01과 같이 0 다음에 1이 오는 경우 - 무조건 0이 거짓말임.
	else if(oneidx == -1) answer = zeroidx + 1; // 1을 못 찾은 경우 - 0 뒤에 있는 것들은 모두 참이니 zeroidx까지
	else if(zeroidx == s.length()) answer = s.length() - oneidx; // 0을 못 찾은 경우 - 1 앞에 있는 것은 모두 참이니 oneidx부터 끝까지
	else answer = zeroidx - oneidx + 1; // 0, 1 둘 다 있는 경우 - 1과 0 사이(포함)

	cout<<answer<<'\n';
}

/*
제일 앞의 0과 제일 뒤의 1을 가지고 뭐 할 것 같은데...


0 뒤에 오는 0은 참일 수 밖에 없음
뒤에 오는 0이 거짓말 - 그 앞사람은 참이기 때문임.
같은 논리로 0 뒤에 오는 ?는 참일 수 밖에 없음
뒤에 오는 ?가 거짓 - 그 앞사람은 참이기 때문
따라서, 0 뒤에 뭔가 있으면 제일 앞의 0은 용의자임

마찬가지로 1 앞에 오는 1은 참일 수 밖에 없음
앞에 오는 1이 거짓말 - 그 뒷사람은 참이기 때문임.
같은 논리로 1 앞에 오는 ?도 참
따라서 1 앞에 1, ?가 있으면 제일 뒤의 1은 용의자

1 앞에 0이 있는 경우
11101 무조건 1임

0 뒤에 1이 있는 경우
01 무조건 1임

*/

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	////////////////////// write your code below
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	//////////////////////

	return 0;
}