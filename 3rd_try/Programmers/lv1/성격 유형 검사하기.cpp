#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> surveies, vector<int> choices) {
    int len = surveies.size();
    
    map<char, int> points; // [type, 점수]
    
    for(int i = 0; i<len; i++){
        string survey = surveies[i];
        int choice = choices[i];
        
        if(choice < 4){ // survey[0]의 점수++
            char type = survey[0];
            int point = 4 - choice;
            points[type] += point;
        }
        else if(choice > 4){ // survey[1]에 점수++
            char type = survey[1];
            int point = choice - 4;
            points[type] += point;
        }
        // *** 실수: choice == 4인 경우에는 else로 걸림.
    }
    
    // cal
    string answer = "XXXX";
    vector<string> indexes = {"RT", "CF", "JM", "AN"};
    for(int i = 0; i<4; i++){
        string index = indexes[i];
        
        if(points[index[1]] > points[index[0]]){
            answer[i] = index[1];
        }
        else{
            answer[i] = index[0];
        }
    }
    return answer;
}