
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> toppings) {
    map<int, int> left, right; // left : 왼쪽 조각의 토핑, right : 오른쪽 조각의 토핑
    // 초기 상태 : 안 자른 상태, right에 다 넣음
    for(int topping : toppings){
        if(right.find(topping) == right.end()){
            right[topping] = 1;
        } else{
            right[topping]++;
        }
    }

    int answer = 0;
    // middle pointer를 옮겨가면서 right 중 leftmost topping을 1개씩 left로 옮길 것.
    for(int topping : toppings){
		if (right[topping] == 1){ // right 중 leftmost 삭제
			right.erase(topping);
		}
		else{
			right[topping]--;
		}

		if (left.find(topping) == left.end()){ // 그것을 left에 삽입
			left[topping] = 1;
		}
		else{
			left[topping]++;
		}

		if(left.size() == right.size()) answer++;
    }

    return answer;
}