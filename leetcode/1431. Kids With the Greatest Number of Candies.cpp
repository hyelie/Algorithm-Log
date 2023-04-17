// Runtime 0 ms Beats 100%
// Memory 8.9 MB Beats 86.24%

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> answer(n, false);
        for(int i = 0; i<n; i++){
            if(candies[i] + extraCandies >= maxCandies) answer[i] = true;
        }
        return answer;
    }
};