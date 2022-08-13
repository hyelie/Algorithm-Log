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

using namespace std;

int solution(vector<int> orders) {
    int answer = 0, n = orders.size();
    int target, i;
    stack<int> stk;
    for(target = 1, i = 0; i<orders.size();){
        // target : 현재 제일 앞에 있는 것
        if(target == orders[i]){ // 순서가 맞으면 바로 넣음
            answer++;
            i++;
            target++;
        }
        else if(target < orders[i]){ // target보다 더 큰 걸 올려야 하면 target부터 orders[i]-1까지 sub에 넣음
            while(target <= n && target < orders[i]){
                stk.push(target);
                target++;
            }
        }
		else{ // target보다 더 작은 걸 올려야 하면 stack에서 빼내야 함.
			if (!stk.empty() && stk.top() == orders[i]){ // 만약 top이 그것이라면 빼면 됨
				stk.pop();
				i++;
				answer++;
			} else{ // 그런데, stack에서 못 뺀다면 더 이상 순서를 맞출 수 없음
				break;
			}
		} 
	}

    return answer;
}
/*
sub container belt는 stack임
*/

/*
sub container belt는 stack임
*/

/*
벽을 부쉈다면(didBroke가 true) false로 넘어갈 수 없음
벽을 부수지 않았다면 (false라면) true로 갈 수도 있고 false를 유지할 수도 있음
*/

//////////////////////

int main(void) {
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	vector<int> orders(5);
	for(int &order : orders) cin>>order;
	solution(orders);

	return 0;
}