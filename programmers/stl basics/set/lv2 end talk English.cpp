// 영어 끝말잇기

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    int size = words.size();
    set<string> word_set;
    
    if(words[0].length() == 1){
        answer[0] = answer[1] = 1; return answer;
    }
    
    word_set.insert(words[0]);
    for(int i = 1; i<size; i++){
        if(words[i-1].back() != words[i].front() || words[i].length() == 1 || word_set.find(words[i]) != word_set.end()){
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        word_set.insert(words[i]);
    }
    
    return answer;
}