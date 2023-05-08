// Runtime 13 ms Beats 75.43%
// Memory 11.2 MB Beats 64.67%

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int answer = 0, n = mat.size();
        for(int i = 0; i<n; i++){
            answer += mat[i][i] + mat[i][n-i-1];
            if(i == n-i-1) answer -= mat[i][i];
        }
        return answer;
    }
};