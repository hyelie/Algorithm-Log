class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int max_score = 0;
        sort(tokens.begin(), tokens.end(), less<int>());

        // early return
        int len = tokens.size();
        if(len == 0) return 0;
        if(len == 1){
            if(tokens[0] <= power) return 1;
            else return 0;
        }

        // two-pointer
        int start = 0, end = len-1, score = 0;
        while(start < end){
            while(start <= end && tokens[start] <= power){
                score++;
                power -= tokens[start];
                start++;
                max_score = max(max_score, score);
            }
            if(start < end && end >= 0){
                score--;
                if(score < 0) {
                    score = 0;
                    end--;
                    continue;
                }
                power += tokens[end];
                end--;
            }
        }

        return max_score;
    }
};

/*
한 토큰당 아래 2개 중 하나 선택 가능.

up: power가 token[i]보다 큰 경우 token[i]만큼 power 감소, 1점 획득
down: score가 1보다 큰 경우, token[i]만큼 power 증가, 1점 잃음

최대 점수

어려운데 ?


1. 최대한 score를 많이 산다.
2. 제일 높은 걸로 1점을 판다.
이걸 반복?
*/