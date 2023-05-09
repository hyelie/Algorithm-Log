class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), cnt = 0;
        vector<int> answer;
        int numRepeat = min((m+1)/2, (n+1)/2);
        int rowStart = 0, rowEnd = m-1, colStart = 0, colEnd = n-1;
        for(int k = 0; k<numRepeat; k++){ // cycle 시작지점이 몇 개인지
            for(int j = colStart; j<=colEnd; j++){
                answer.push_back(matrix[rowStart][j]);
            }
            rowStart++;
            
            for(int i = rowStart; i<=rowEnd; i++){
                answer.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            if(rowEnd >= rowStart){
                for(int j = colEnd; j>=colStart; j--){
                    answer.push_back(matrix[rowEnd][j]);
                }
                rowEnd--;
            }

            if(colEnd >= colStart){
                for(int i = rowEnd; i>=rowStart; i--){
                    answer.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }
        return answer;
    }
};

/*
제일 겉면을 하나씩 벗겨나가는 식으로 하면 될 듯.
*/