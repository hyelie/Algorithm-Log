// Runtime 102 ms Beats 14.37%
// Memory 37.1 MB Beats 7%

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2;
        for(int n : nums1) set1.insert(n);
        for(int n : nums2) set2.insert(n);

        set<int> result1, result2;
        for(int n : nums1){
            if(set2.find(n) == set2.end()){
                result1.insert(n);
            }
        }
        for(int n : nums2){
            if(set1.find(n) == set1.end()){
                result2.insert(n);
            }
        }

        vector<int> r1(result1.begin(), result1.end());
        vector<int> r2(result2.begin(), result2.end());

        return {r1, r2};
    }
};