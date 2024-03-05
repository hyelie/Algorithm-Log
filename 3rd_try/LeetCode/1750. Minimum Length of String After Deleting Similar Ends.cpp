class Solution {
public:
    int minimumLength(string s) {
        int start = 0, end = s.length()-1, len = s.length();

        while(1){
            if(start > end) return 0;
            
            if(s[start] != s[end]) return end - start + 1;

            char sc = s[start], ec = s[end];

            if(end == start && sc == ec) return 1;

            while(start < len && s[start] == sc){
                start++;
            }
            while(end >= 0 && s[end] == ec){
                end--;
            }
        }
    }
};

/*
two pointer vs 중복 없애기
*/