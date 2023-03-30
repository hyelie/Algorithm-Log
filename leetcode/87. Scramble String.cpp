// Runtime 177 ms Beats 39.14%
// Memory 37.1 MB Beats 32.82%

class Solution {
public:
    unordered_map<string, bool> um;

    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        string key = s1 + " " + s2;
        if(um.find(key) != um.end()) return um[key];

        for(int len = 1; len<s1.length(); len++){
            // x + y
            bool xy = isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len));
            
            if(xy){
                um[key] = true;
                return true;
            }   

            //isScramble(s1.substr(0, len), s2.substr(0, len)); // s1 앞부분, s2 앞부분
            //isScramble(s1.substr(len), s2.substr(len)); // s1 뒷부분, s2 뒷부분

            // y + x
           bool yx = isScramble(s1.substr(0, len), s2.substr(s2.length() - len)) && isScramble(s1.substr(len), s2.substr(0, s2.length() - len));
            if(yx){
                um[key] = true;
                return true;
            }
            //isScramble(s1.substr(0, len), s2.substr(s2.length() - len)); // s1의 앞부분, s2 뒷부분
            //isScramble(s1.substr(len), s2.substr(0, s2.length() - len)); // s1의 앞부분, s2 앞부분
        }
        um[key] = false;
        return false;
    }
};