// Runtime 0 ms Beats 100%
// Memory 6.5 MB Beats 90.43%

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = n-1, cnt = 1;
        for(int k = 0; k<(n+1)/2; k++){
            for(int j = colStart; j<=colEnd; j++){
                m[rowStart][j] = cnt; cnt++;
            }
            rowStart++;
            
            for(int i = rowStart; i<=rowEnd; i++){
                m[i][colEnd] = cnt; cnt++;
            }
            colEnd--;

            if(rowEnd >= rowStart){ // 앞에서 rowStart-- 하므로 같을 수도 있음
                for(int j = colEnd; j>=colStart; j--){
                    m[rowEnd][j] = cnt; cnt++;
                }
                rowEnd--;
            }
            
            if(colEnd >= colStart){ // 이하동문
                for(int i = rowEnd; i>=rowStart; i--){
                    m[i][colStart] = cnt; cnt++;
                }
                colStart++;
            }

        }

        return m;
    }
};