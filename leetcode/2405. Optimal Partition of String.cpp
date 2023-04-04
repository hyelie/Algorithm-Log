// Runtime 325 ms Beats 5.4%
// Memory 88 MB Beats 8.67%

class Solution {
public:
    int partitionString(string s) {
        int answer = 0, i = 0, len = s.length();

        while(i < len){
            unordered_map<char, int> um;
            while(i < len && um.find(s[i]) == um.end()){
                um[s[i]] = 1;
                i++;
            }
            answer++;
        }

        return answer;
    }
};



// Runtime 23 ms Beats 90.1%
// Memory 10.2 MB Beats 98.68%

class Solution {
public:
    int partitionString(string s) {
        int answer = 1, len = s.length(), curSubstrIdx = 0;
        vector<int> lastCharIdx(26, -1);

        for(int i = 0; i<len; i++){
            if(lastCharIdx[s[i] - 'a'] >= curSubstrIdx){
                answer++;
                curSubstrIdx = i;
            }
            lastCharIdx[s[i] - 'a'] = i;
        }

        return answer;
    }
};