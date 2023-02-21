// runtime 16ms, beats 99.39%
// memory 22.3MB, beats 62.74%

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int start = 0; // 시작 index
        int end = nums.size() - 1; // 끝 index
        int middle; // 가운데 index

        while(end != start){ // 길이가 1이 될 때까지 반복
            middle = (start + end) / 2;
            if(nums[middle] != nums[middle -1] && nums[middle] != nums[middle + 1]) return nums[middle]; 
            
            else if(nums[middle] == nums[middle -1]){
                if(middle % 2){
                    start = middle + 1;
                }
                else{
                    end = middle - 2; // middle과 middle-1은 같은 수이므로 middle-2로 갱신
                }
            }
            else {  // nums[middle] == nums[middle + 1]
                if(middle % 2){
                    end = middle - 1;
                }
                else{
                    start = middle + 2; // middle과 middle+1은 같은 수이므로 middle+2로 갱신
                }
            }
        }

        return nums[start];
    }
};