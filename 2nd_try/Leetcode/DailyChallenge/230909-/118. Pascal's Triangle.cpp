// Runtime 0 ms Beats 100%
// Memory 6.9 MB Beats 20.86%

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> answer;
        answer.push_back({1});

        for(int l = 1; l<n; l++){
            vector<int> layer(l+1);
            layer[0] = layer[l] = 1;
            for(int i = 1; i<l; i++){
                layer[i] = answer[l-1][i] + answer[l-1][i-1];
            }
            answer.push_back(layer);
        }

        return answer;
    }
};