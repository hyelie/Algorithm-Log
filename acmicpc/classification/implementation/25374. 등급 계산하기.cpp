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
그냥 빡구현 문제네. 어렵다.
위에서부터 채우고, 넘치는 경우 다음 할당 인원에서 빼는 식으로?
*/

void solve(){
	int N; cin>>N;
    vector<int> points(N); for(int i = 0; i<N; i++) cin>>points[i];

    sort(points.begin(), points.end(), greater<int>());

    // vector<int> cuts = {0, 4, 11, 23, 40, 60, 77, 89, 96, 100}; // 차례대로 1등급 ~ 9등급에 할당될 등수, 1-indexing
    vector<int> cuts = {0, 4, 7, 12, 17, 20, 17, 12, 7, 4}; // 차례대로 1등급 ~ 9등급에 할당될 인원. 1-indexing
    vector<int> answer(10, 0); // 1-indexing

    int grade = 1; answer[grade]++; cuts[grade]--; // *** 실수 : 1등을 넣었으면 1등급 할당 인원에서 1명 빼야 했다.
    for(int i = 1; i<N; i++){
        // 현재 등급에 넣을 수 있는 경우, 넣는다.
        // 넣을 수 없는 경우, 다음 등급을 탐색한다.
        // 단, 넣을 수 없는 경우이지만 이전 등수와 점수가 같은 경우 다음 등급에 있는 인원수를 하나 빼앗아 현재 등급에 할당한다.

        if(cuts[grade] > 0){
            
        }
        else{
            if(points[i-1] == points[i]){
                int nextGrade = grade + 1;
                while(cuts[nextGrade] == 0) nextGrade++; // 할당할 수 있는 등급이 나올 때까지 등급 뒤로 감.
                cuts[grade]++;
                cuts[nextGrade]--;
            }
            else{
                int nextGrade = grade + 1;
                while(cuts[nextGrade] == 0) nextGrade++; // 할당할 수 있는 등급이 나올 때까지 등급 뒤로 감.
                grade = nextGrade;
            }
        }
        answer[grade]++;
        cuts[grade]--;
    }

    for(int i = 1; i<10; i++) cout<<answer[i]<<'\n';
}

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	solve();

	return 0;
}