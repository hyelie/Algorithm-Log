// Runtime 9 ms Beats 48.47%
// Memory 8.1 MB Beats 37.2%


class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> rq, dq; // queue 2개
        for(int i = 0 ; i<senate.length(); i++){
            if(senate[i] == 'R') rq.push(i);
            else dq.push(i);
        }

        while(!rq.empty() && !dq.empty()){
            int rqFrontIdx = rq.front(); rq.pop();
            int dqFrontIdx = dq.front(); dq.pop();
            if(rqFrontIdx < dqFrontIdx) rq.push(rqFrontIdx + n); // 더 작은 index는 더 큰 index의 것을 없앤다. 그것이 optimal이다.
            else dq.push(dqFrontIdx + n);
        }

        if(!rq.empty()) return "Radiant";
        else return "Dire";
    }
};

/*
optim