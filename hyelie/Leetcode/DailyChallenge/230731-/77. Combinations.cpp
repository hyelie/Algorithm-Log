// Runtime 10 ms Beats 93.32%
// Memory 9.9 MB Beats 56.99%

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> answer;
    void combination(int cur_d, int max_d, int prev_idx, vector<int>& result){
        if(cur_d == max_d){
            answer.push_back(result);
            return;
        }

        for(int i = prev_idx + 1; i<nums.size(); i++){
            result[cur_d] = nums[i];
            combination(cur_d+1, max_d, i, result);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i<=n; i++) nums.push_back(i);
        vector<int> result(k);

        combination(0, k, -1, result);

        return answer;
    }
};

/*
조합 문제, backtracking
*/