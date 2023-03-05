// Runtime 181 ms Beats 97.86%
// Memory 73 MB Beats 76.87%

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        vector<int> dp(arr.size(), -1); // -1 : unvisited
        unordered_map<int, vector<int>> m; // 개선 : map -> unordered_map
        for(int i = 0; i<n; i++){
            m[arr[i]].push_back(i);
        }

        queue<int> q; // BFS
        q.push(0);
        dp[0] = 0;

        while(!q.empty()){
            int idx = q.front(), dist = dp[idx]; q.pop();
            if(idx == n-1) break;
            // 개선 : map에 있을 때만 find 이후 erase
            if(m.find(arr[idx]) != m.end()){
                for(int sameidx : m[arr[idx]]){
                    if(dp[sameidx] == -1){
                        dp[sameidx] = dp[idx] + 1;
                        q.push(sameidx);
                    }
                }   
                m.erase(arr[idx]);
            }
            
            if(idx + 1 < n && dp[idx + 1] == -1){
                dp[idx + 1] = dp[idx] + 1;
                q.push(idx + 1);
            }
            if(idx - 1 > 0 && dp[idx - 1] == -1){
                dp[idx - 1] = dp[idx] + 1;
                q.push(idx - 1);
            }
        }

        return dp[n-1];
    }
};