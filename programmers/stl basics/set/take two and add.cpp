// 두 개 뽑아서 더하기

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> s;
    int numbers_size = numbers.size();
    for(int i = 0; i<numbers_size; i++){
        for(int j = i+1; j<numbers_size; j++){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer;
    for(int elem : s){
        answer.push_back(elem);
    }
    
    
    return answer;
}