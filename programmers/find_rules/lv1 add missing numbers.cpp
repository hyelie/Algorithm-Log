// 없는 숫자 더하기


#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> numbers) {
    set<int> s;
    for(int i = 0; i<=9; i++){
        s.insert(i);
    }
    
    for(int number : numbers){
        s.erase(number);
    }
    
    int answer = 0;
    for(int elem : s)
        answer += elem;

    return answer;
}