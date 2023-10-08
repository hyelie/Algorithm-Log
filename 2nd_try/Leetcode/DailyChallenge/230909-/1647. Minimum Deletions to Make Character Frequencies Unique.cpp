// Runtime 42 ms Beats 93.66%
// Memory 17.3 MB Beats 77.52%

class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26, 0); // f[i] : frequency of ith alphabet
        for(char c : s){
            f[c - 'a']++;
        }
        sort(f.begin(), f.end(), greater<int>());

        // f가 겹치는 것들이 있는 경우, 몇 개의 letter를 삭제해 겹치지 않게 바꿔야 함.
        // 내린 값이 겹치지 않게 설정해야 함. 그 중 제일 큰 값으로.
        int answer = 0;
        for(int i = 1; i<f.size(); i++){
            // 만약 겹치는 경우! i번째 char를 줄여야 함.
            if(f[i] == 0) continue;

            if(f[i-1] <= f[i]){
                f[i]--;
                answer++;
                i--;
            }
        }

        // print(f);

        return answer;
    }
};

// Runtime 49 ms Beats 79.99%
// Memory 17.3 MB Beats 58%

class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26, 0); // f[i] : frequency of ith alphabet
        for(char c : s){
            f[c - 'a']++;
        }

        priority_queue<int, vector<int>, less<int>> pq;

        for(int e : f){
            pq.push(e);
        }

        int answer = 0;
        while(!pq.empty()){
            int t = pq.top(); pq.pop();
            if(t == 0 || pq.size() == 0) break;
            if(t > 0 && pq.top() == t){
                answer++;
                pq.push(t-1);
            }
        }

        return answer;
    }
};