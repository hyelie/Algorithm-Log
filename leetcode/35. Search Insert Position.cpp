class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();

       int start = 0, end = nums.size(); 
       while(start < end){
           int middle = (start + end) / 2;
           if(nums[middle] >= target){
               end = middle;
           }
           else{
               start = middle + 1;
           }
       }
       return end;
    }
};
