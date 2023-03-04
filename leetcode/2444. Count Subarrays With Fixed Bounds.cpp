// Runtime 114 ms Beats 84.8%
// Memory 70.4 MB Beats 57.55%

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0;
        int lastMax = -1, lastMin = -1, n = nums.size(), start = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] > maxK || nums[i] < minK){
                start = i;
                lastMax = -1; // not found
                lastMin = -1; // not found
            }
            else{
                if(nums[i] == minK) lastMin = i;
                if(nums[i] == maxK) lastMax = i;

                if(lastMin != -1 && lastMax != -1){
                    answer += min(lastMax, lastMin) - start;
                }
            }
        }
        return answer;
    }
};