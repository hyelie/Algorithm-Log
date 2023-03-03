class Solution {
public:
    int strStr(string p, string c) {
        if(p.length() < c.length()) return -1;
        for(int i = 0; i<p.length() - c.length() + 1; i++){
            if(p.substr(i, c.length()) == c) return i;
        }
        return -1;
    }
};