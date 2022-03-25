#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int completion_size = completion.size();
    for(int i = 0; i<completion_size; i++){
        if(participant[i] != completion[i]) return participant[i];
    } return participant[completion_size];
}

// 1 <= participant.size() <= 100000
// completion.size() = participant.size()-1
// each string size <= 20, small letter of alphabet, it can be same.