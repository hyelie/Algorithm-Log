// Runtime 0 ms Beats 100%
// Memory 7.7 MB Beats 41.71%

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(int stone : stones) pq.push(stone);

        while(pq.size() > 1){
            int f = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            if(f != s) pq.push(abs(f - s));
        }

        if(pq.empty()) return 0;
        return pq.top(); // *** 실수 : 종료조건
    }
};  