#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    
    int answer = 0;
    int size = score.size();
    for(int i = m-1; i < size; i += m){
        answer += score[i] * m;
    }
    
    return answer;
}

// 내림차순 sort해서, 높은 순부터 m개씩 묶으면 되겠네.