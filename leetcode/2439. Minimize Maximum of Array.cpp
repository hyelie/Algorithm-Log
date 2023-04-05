// Runtime 123 ms Beats 94.48%
// Memory 71.4 MB Beats 28.9%

typedef long long ll;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int len = nums.size();
        ll psum = nums[0];
        int answer = (int)psum;
        for(int i = 1; i < len; i++){
            psum += nums[i];
            answer = max(answer, (int)(psum / (i+1) + (psum % (i+1) == 0 ? 0 : 1)));
        }
        
        return answer;
    }
};

/*
오름차순인 부분수열에 대해 그들의 평균값이 될 수 있음. 남는 것은 균등히 분배.
1 3 5라면 -> 3 3 3이 될 것.

1 3 6이라면 -> 3 3 4가 될 것.

1 3 7이라면 -> 3 4 4가 될 것.

따라서 오름차순 부분수열을 찾고, [그 부분수열의 합의 평균] + [나머지 존재 then 1 else 0]

음... 

[6,9,3,8,14]
7 8 8 8 9

전체 수열을 잘 조절해서 monotonic increasing으로 만들어야 함.

3
1 3 - 2
7 1 3 - 4
3 7 1 3 - 4
뒤에서부터 오면서 앞으로 보낼 수 있는 경우에는 앞으로 보내는 것을 하면 될 듯?

*/