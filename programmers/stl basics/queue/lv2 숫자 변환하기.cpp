#include <string>
#include <vector>
#include <queue>

using namespace std;

int MAX_VALUE = 1000001, INF = 1000001;

typedef pair<int, int> pii;

int solution(int x, int y, int n) {
    vector<int> dp(MAX_VALUE, INF);
    queue<pii> q; // .first : number, .second : count
    dp[x] = 0; // mistake
    q.push({x, 0});
    
    while(!q.empty()){
        pii front = q.front(); q.pop();
        int number = front.first, count = front.second;
        
        if(number + n < INF && dp[number + n] > count + 1){
            dp[number + n] = count + 1;
            q.push({number + n, dp[number + n]});
        }
        if(number * 2 < INF && dp[number * 2] > count + 1){
            dp[number * 2] = count + 1;
            q.push({number * 2, dp[number * 2]});
        }
        if(number * 3 < INF && dp[number * 3] > count + 1){
            dp[number * 3] = count + 1;
            q.push({number * 3, dp[number * 3]});
        }
    }
    
    return dp[y] == INF ? -1 : dp[y];
}