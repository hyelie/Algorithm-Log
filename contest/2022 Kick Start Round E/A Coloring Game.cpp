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

int solve(){
	int N; cin>>N; // # of cells in game
	// cell이 white고 red color cell이 없으면 valid
	// bot은 제일 왼쪽의 valid cell 고름
	// valid 없으면 게임 종료,
	// 각 턴마다 valid 칠함

	/*
		cell이 짝수면 
		cell이 홀수면 
		P는 점수 안줄려고 할 거니까 B가 둔 것의 오른쪽 3칸에 둘 것
		5단위로 끊김

		ㅁ -> B
		ㅁㅁ -> Bㅁ
		ㅁㅁㅁ -> BㅁP
		ㅁㅁㅁㅁ -> BㅁㅁP
		ㅁㅁㅁㅁㅁ -> BㅁㅁPㅁ
		ㅁㅁㅁㅁㅁㅁ -> BㅁㅁPㅁ B
		ㅁㅁㅁㅁㅁㅁㅁ -> BㅁㅁPㅁ Bㅁ
		ㅁㅁㅁㅁㅁㅁㅁㅁ -> BㅁㅁPㅁ BㅁP
		ㅁㅁㅁㅁㅁㅁㅁㅁㅁ -> BㅁㅁPㅁ BㅁㅁP
		ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ -> BㅁㅁPㅁ BㅁㅁPㅁ
	*/
	int answer = N/5 + (N%5 == 0 ? 0 : 1);
	return answer;

}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
	for(int i =1; i<=t; i++){
		cout<<"Case #"<<i<<": "<<solve()<<'\n';
	}

	return 0;
}
