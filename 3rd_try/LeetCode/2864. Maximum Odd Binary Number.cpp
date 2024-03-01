class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length(), ones = 0;
        for(char c : s){
            if(c == '1') ones++;
        }

        int i = 0;
        for(i = 0; i< len && ones > 1; i++, ones--){
            s[i] = '1';
        }
        for(; i<len-1; i++){
            s[i] = '0';
        }
        s[len-1] = '1';

        return s;

    }
};