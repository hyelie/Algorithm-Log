// Runtime 0 ms Beats 100%
// Memory 6.7 MB Beats 18.80%

class Solution {
public:
    vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> answer;
    void permutation(int cur_depth, int max_depth, string &result, string &digits){
        if(cur_depth == max_depth){
            answer.push_back(result);
            return;
        }

        int number = digits[cur_depth] - '0';
        for(char c : mappings[number]){
            result[cur_depth] = c;
            permutation(cur_depth + 1, max_depth, result, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return answer;

        string result = "";
        for(int i = 0; i<digits.size(); i++) result += ".";

        permutation(0, (int)digits.size(), result, digits);

        return answer;
    }
};

/*

*/