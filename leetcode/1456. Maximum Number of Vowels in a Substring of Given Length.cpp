// Runtime 11 ms Beats 99.57%
// Memory 9.9 MB Beats 68.38%

class Solution {
public함
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int numVowels = 0, len = s.length();
        for(int i = 0; i<k; i++){
            if(isVowel(s[i])) numVowels++;
        }
        int answer = numVowels; // *** 실수 : answer를 여기에 지정해 주어야 하
        for(int i = k; i<len; i++){
            if(isVowel(s[i])) numVowels++;
            if(isVowel(s[i-k])) numVowels--;
            answer = max(numVowels, answer);
        }

        return answer;
    }
};