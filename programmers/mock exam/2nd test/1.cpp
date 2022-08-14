#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    int n = number.size();
    for(int i = 0; i<n; i++){
        for(int j = i + 1; j<n; j++){
            for(int k = j + 1; k<n; k++){
                if(number[i] + number[j] + number[k] == 0) answer++;
            }
        }
    }

    return answer;
}

// 그냥 3중포문으로 풀면 되는 문제