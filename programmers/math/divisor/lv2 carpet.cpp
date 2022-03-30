// 카펫

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(int brown, int yellow) {
    vector<pii> divisors;
    vector<int> answer;
    
    for(int i = 1; i <= sqrt(yellow); i++){
        if(yellow % i == 0){
            divisors.push_back({yellow / i, i});
        }
    }
    
    
    for(pii divisor : divisors){
        if((divisor.first + 2) * 2 + (divisor.second + 2) * 2 - 4 == brown){
            answer.push_back(divisor.first + 2);
            answer.push_back(divisor.second + 2);
            break;
        }
    }
    return answer;
   
}
// 가로 길이 >= 세로길이
// nlogn : 5백만까지 풀어짐.
// 약수 탐색하는 문제임 !
// 노란색 가로 * 2 + 세로 * 2 - 4 = brown









/*vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    vector<pair<int, int>> divisor;
    for(int i = 2; i<=sqrt(sum); i++){
        if(sum % i == 0) divisor.push_back({i, sum/i});
    }
    
    vector<int> answer;
    
    for(int i = 0; i<divisor.size(); i++){
        if(yellow == (divisor[i].first-2) * (divisor[i].second-2)){
            answer.push_back(divisor[i].second);
            answer.push_back(divisor[i].first);
            break;
        }
    }
    
    
    return answer;
}*/

// 합의 약수 모든 조합 구하고

// sqrt(sum)보다 작은 모든 약수 구해서 
// 가로-1 * 세로-1이 yellow 되면 되는 것