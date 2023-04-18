// Runtime 2 ms Beats 50.88%
// Memory 6.5 MB Beats 19.57%

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, len1 = word1.length(), len2 = word2.length();
        string result = "";
        while(i < len1 && j < len2){
            result += word1[i]; i++;
            result += word2[j]; j++;
        }
        while(i < len1){
            result += word1[i]; i++;
        }
        while(j < len2){
            result += word2[j]; j++;
        }
        return result;
    }
};