// 구명보트

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int cnt = 0, start = 0, end = people.size()-1;
    
    while(start <= end){
        cnt++;
        if(start == end) break;
        else if(people[end] + people[start] <= limit){
            start++; end--;
        } else{
            end--;
        }
    }

    return cnt;
    
    
}

/*
50 50 70 80
젤 뒷사람 보고
젤 앞사람이랑 같이 탈 수 있으면 타고
그렇지 않으면 젤 뒷사람만 태우면 될 것 같은데 ?
*/









/*int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int s, e, num = people.size();
    
    for(s = 0, e = num-1; s<=e;){
        if(people[s] + people[e] > limit){
            e--;
            answer++;
        }
        else{
            e--;
            s++;
            answer++;
        }
    }
    
    
    return answer;
}*/