class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());

        set<int> result;
        for(int num : nums2){
            if(s.find(num) != s.end()){
                result.insert(num);
            }
        }

        vector<int> sresult(result.begin(), result.end());
        return sresult;
    }
};