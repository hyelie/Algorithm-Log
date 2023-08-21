// Runtime 19 ms Beats 64.17%
// Memory 15.4 MB Beats 38.41%

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for(int i = 0; i<len/2; i++){
            if(len % (i+1) == 0){
                string substr = s.substr(0, i+1);
                bool repeated = true;
                for(int q = 1; q<len/(i+1); q++){
                    if(s.substr(q*(i+1), i+1) != substr) {
                        repeated = false;
                        break;
                    }
                }
                if(repeated) return true;
            }
        }
        return false;
    }
};