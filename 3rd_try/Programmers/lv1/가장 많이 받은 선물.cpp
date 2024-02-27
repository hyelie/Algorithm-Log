#include <string>
#include <vector>
#include <set>
#include <sstream>
#include<iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> friends, gifts;
map<string, map<string, int>> logs; // 누가 누구에게 몇번 줬는지
map<string, int> index; // 지수

void parse(string gift){
    istringstream iss(gift);
    string from, to;
    iss >> from >> to;
    
    logs[from][to]++;
    
    index[from]++;
    index[to]--;
}

int solution(vector<string> _friends, vector<string> _gifts) {
    friends = _friends; gifts = _gifts;
    for(string f : friends){
        index[f] = 0;
    }
    
    for(string gift : gifts){
        parse(gift);
    }
    
    int answer = 0;
    for(string from : friends){
        int willGivenNum = 0;
        
        for(string to : friends){
            if (from == to) continue;
            
            int sendNum = logs[from][to];
            int givenNum = logs[to][from];
            
            if(sendNum > givenNum){
                willGivenNum++;
            }
            else if(sendNum == givenNum && index[from] > index[to]){
                willGivenNum++;
            }
            
            answer = max(answer, willGivenNum);
        }
    }
    return answer;
}