class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0; // i: nums1 ptr, j : nums2 ptr
        // two-pointer

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]) return nums1[i];

            if(nums1[i] > nums2[j]) j++;
            else if(nums1[i] < nums2[j]) i++;
        }

        return -1;
    }
};