// Runtime 0 ms Beats 100%
// Memory 8 MB Beats 98.26%

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        int sum = 0, idx = -1; // 실수 : idx가 없을 때 값이 들어가지 않을 수 있었음.
        for(int i = 0; i<n; i++){
            if(sum + satisfaction[i] < 0) break;
            sum += satisfaction[i];
            idx = i;
        }

        sum = 0;
        for(int i = idx, cnt = 1; i>=0; i--, cnt++){
            sum += satisfaction[i] * cnt;
        }
        return sum;
    }
};

// 시작지점을 고르면 될 듯?
// psum 쓰면 쉽게 풀릴 것 같은데.
// greedy?
// -9 -8 -1 0 5

/*
오름차 정렬되어 있는 상태에서, 제일 끝 index i에서 앞으로 한 칸 당기면 
arr[i-1] + arr[i] + ... + arr[n-1]을 더해야 함. : 이 psum이 0보다 작아지기 직전에 끊으면 됨

그럼 거꾸로, 내림차 정렬되어 있는 상태에서 arr[0] + ... + arr[i]가 0보다 작아지기 직전에 끊는 i에 대해 i가 답.
그러면 psum 사용할 필요가 없음.
*/
