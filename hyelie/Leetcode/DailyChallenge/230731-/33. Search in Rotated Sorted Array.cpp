// Runtime 0 ms Beats 100%
// Memory 11.2 MB Beats 13.70%

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start < end){
            int mid = (start + end)/2;

            if(nums[mid] < nums[end]) end = mid; // 앞으로 당김
            else start = mid + 1;
        }
        cout<<end<<endl;
        // result : 작아진 첫 idx

        int pivot = end;
        // 이걸 사용해서 circular처럼 쓸 수 있음.
        start = 0; end = nums.size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            int idx = (mid + pivot) % nums.size();
            if(nums[idx] == target) return idx;
            if(nums[idx] > target) end = mid - 1;
            else start = mid + 1;
        }
        
        return -1;
    }
};

/*
upper bound로 
*/