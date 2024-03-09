#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool>> weight(n+1, vector<bool>(n+1, false));
    for(vector<int> result : results){
        int win = result[0], lose = result[1];
        weight[win][lose] = true;
    }
    for(int i =1; i<=n; i++) weight[i][i] = false;
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(i == j) continue;
                if(weight[i][k] && weight[k][j]) weight[i][j] = true;
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i<=n; i++){
        int cnt = 0;
        for(int j = 1; j<=n; j++){
            if(weight[i][j] || weight[j][i]) cnt++;
        }
        
        if(cnt >= n-1) answer++;
    }
    
    return answer;
}