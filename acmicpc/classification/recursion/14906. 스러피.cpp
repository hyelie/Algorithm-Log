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

/*
우선, 스럼프(Slump)는 다음 조건을 만족하는 문자열이다.

첫 번째 문자가 ‘D’ 또는 ‘E’ 이다.
첫 번째 문자 뒤에는 하나 이상의 ‘F’가 반복되어 연달아 나온다.
위 2의 조건에서 반복되는 ‘F’ 뒤에는 또 다른 스럼프나 ‘G’가 온다. 따라서 항상 스럼프는 ‘F’ 끝에 오는 스럼프나 ‘G’로 끝난다. 예를 들어, DFFEFFFG는 첫 번째 문자가 ‘D’로 시작하고 두 개의 ‘F’가 연달아 나오며, 또 다른 스럼프 ‘EFFFG’로 끝난다. (똑같은 방식으로 ‘EFFFG’는 스럼프임을 알 수 있다)
위의 경우가 아니면 스럼프가 아니다.


그리고 스림프(Slimp)는 다음 조건을 만족하는 문자열을 말한다.

첫 번째 문자는 ‘A’이다.
두개의 문자로만 된 스림프이라면 두 번째 문자는 ‘H’이다.
세 개이상의 문자로 된 스림프라면 다음중 하나의 형식을 띈다.
‘A’ + ‘B’ + 스림프 + ‘C’
‘A’ + 스럼프 + ‘C’
스림프는 길이 2이상이며, 위의 경우가 아니면 스림프가 아니다
마지막으로 스러피는 ‘스림프 + 스럼프’로 구성되는 문자열이라고 정의한다.


1. 뒤에서 처음으로 D나 E가 나오는 곳 잡음. 그 앞은 slimp, 그 뒤는 slump여야 함
2. slimp 검증
 - 첫 문자는 A
 - length가 2면 AH
 - 3개 이상이라면 AB + slimp + C / A + slump + C
3. slump 검증
 - 첫 문자는 D 또는 E
 - 그 뒤에는 연속된 F가 있고, legnth >= 1
 - [D/E][F...F][G | slump]

 - 재귀식으로 돌리면 될 것 같은데.

4. 앞은 slimp, 그 뒤는 slump
 - slump의 첫 기준인 D/E가 나온 모든 경우, 앞/뒤로 잘라서 둘다 성공하면 OK, 아니면 false

*/

bool isSlump(string s){
    if(!(s[0] == 'D' || s[0] == 'E')) return false;
    if(s[1] != 'F') return false;
    for(int i = 2; i<s.length(); i++){
        if(s[i] == 'F') continue; // 연속된 F
        if(s[i] == 'D' || s[i] == 'E'){ // 새 slump
            return isSlump(s.substr(i));
        }
        else if(s[i] == 'G'){ // 종료
            if(i == s.length()-1) return true;
            else return false;
        }
        else return false;
    }
    return false;
}

bool isSlimp(string s){
    if(s.length() < 2) return false;
    if(s[0] != 'A') return false; // 첫 문자
    if(s.length() == 2){ // length 2면 AH
        if(s[1] == 'H') return true;
        else return false;
    }
    else{
        if(s[1] == 'B' && s[s.length()-1] == 'C' && isSlimp(s.substr(2, s.length()-3))) return true;
        if(s[s.length()-1] == 'C' && isSlump(s.substr(1, s.length()-2))) return true;
        else return false;
    }
}

void solve(){
	string s; cin>>s;
    string result = "NO";
    for(int i = 0; i<s.length(); i++){
        if(s[i] == 'D' || s[i] == 'E'){
            string left = s.substr(0, i), right = s.substr(i);
            if(isSlimp(left) && isSlump(right)){
                result = "YES";
                break;
            }
        }
    }
    cout<<result<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);
	
	// number of test cases
	int t; cin>>t;
    cout<<"SLURPYS OUTPUT"<<'\n';
	while(t--){
		solve();
	}
    cout<<"END OF OUTPUT"<<'\n';
    

	return 0;
}