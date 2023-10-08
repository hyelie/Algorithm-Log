class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        // lower bound로 찾는 식으로 -> matrix[i][0]으로 찾으면 upper bound로 찾고 -1 해야 한다. 귀찮다!
        // 따라서 matrix[i][n-1]로 찾는다. target이 들어 있을 만한 행을 찾기 위해서이다.
        int start = 0, end = m, mid;
        while(start < end){
            mid = (start + end)/2;
            if(matrix[mid][n-1] >= target) end = mid; // 앞으로 당겨야 함
            else start = mid + 1;
        }
        if(end == m || (end == 0 && matrix[0][0] > target)) return false;
        int i = start;
        
        // col 찾기
        start = 0; end = n;
        while(start < end){
            mid = (start + end)/2;
            if(matrix[i][mid] >= target) end = mid; // 앞으로 당겨야 함
            else start = mid + 1;
        }
        if(end == n || matrix[i][end] != target) return false;

        return true;
    }

};

/*
binary search 2번?
*/