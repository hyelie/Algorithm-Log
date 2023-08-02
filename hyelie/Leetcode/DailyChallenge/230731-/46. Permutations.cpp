// Runtime 3 ms Beats 67.29%
// Memory 8 MB Beats 29.89%

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> nums, result;
    vector<bool> isUsed;
    int N;
    void permutation(int cur_depth, int max_depth){
        if(cur_depth == max_depth){
            answer.push_back(result);
            return;
        }

        for(int i = 0; i<N; i++){
            if(!isUsed[i]){
                isUsed[i] = true;
                result[cur_depth] = nums[i];
                permutation(cur_depth + 1, max_depth);
                isUsed[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& num) {
        N = num.size();
        nums = num;
        isUsed.resize(N); result.resize(N);
        fill(isUsed.begin(), isUsed.end(), false);

        permutation(0, N);
        return answer;
    }
};