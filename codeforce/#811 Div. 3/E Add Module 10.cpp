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

string No = "No\n";
string Yes = "Yes\n";

int calculate(int n){
	return n + n%10;
}

int getLastDigit(int n){
	return n%10;
}


/*
0은 평생 0
5는 다음 연산으로 0이 됨
만약 5가 있다면 다음 연산을 해 주고,
 1) arr 중 0이 아닌 것이 하나라도 있거나
 2) 10의 자리가 다르다면
NO, 아닌 경우 YES

2, 4, 6, 8은 x2 - x4 - x8 - (x+1)6 - (x+2)2로 돌아감
1은 다음 연산으로 2가 되고
3은 다음 연산으로 6
5는 다음 연산으로 0
7은 다음 연산으로 4
9는 다음 연산으로 8이 됨

0, 5를 제외하고는 첫 자리가 2가 될 때 까지 다음 연산을 돌림
그리고 10의 자리가 20의 배수로 차이나지 않는 경우 - false

*/

void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		if(getLastDigit(arr[i]) == 5) arr[i] = calculate(arr[i]);
		else if(getLastDigit(arr[i]) == 0) continue;
		else{
			while(getLastDigit(arr[i]) != 2){
				arr[i] = calculate(arr[i]);
			}
		}
	}

	string answer = Yes;
	// 0짜리가 하나라도 있으면 전부 동일해야 함
	bool isDigitZero = false;
	for(int elem : arr){
		if(getLastDigit(elem) == 0){
			isDigitZero = true;
			break;
		}
	}
	if(isDigitZero){
		for(int i = 1; i<arr.size(); i++){
			if(arr[i] != arr[0]){
				answer = No;
				break;
			}
		}
	}
	else{ // 0, 5짜리가 하나도 없는 경우에는 10자리수 차이가 모두 20이어야 함.
		for(int i = 1; i<arr.size(); i++){
			if((arr[i] - arr[0]) % 20 != 0){
				answer = No;
				break;
			}
		}
	}
	cout<<answer;
}

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