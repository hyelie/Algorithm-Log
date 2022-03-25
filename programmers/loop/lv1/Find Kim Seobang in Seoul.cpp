#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int seoul_size = seoul.size(), i = 0;
    for(; i<seoul_size; i++){
        if(seoul[i] == "Kim") break;
    }
    
    string answer = "김서방은 " + to_string(i) + "에 있다";
    return answer;
}