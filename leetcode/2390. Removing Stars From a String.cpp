// Runtime 68 ms Beats 95.74%
// Memory 25.9 MB Beats 57.75%

class Solution {
public:
    string removeStars(string s) {
        string answer = "";
        for(char c : s){
            if(c == '*'){
                answer.pop_back();
            }
            else{
                answer += c;
            }
        }
        return answer;
    }
};