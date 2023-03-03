#include <string>
#include <vector>

using namespace std;

// n : 구역, m : 롤러 길이
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int size = section.size();
    for(int i = 0; i<size; i++){
        int cur = i;
        // 더 이상 칠하지 못할 때까지 section index 증가
        while(cur + 1 < size && section[cur + 1] <= section[i] + m - 1){
            cur++;
        }
        i = cur;
        answer++;
    }
    
    return answer;
}