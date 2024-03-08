class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m; // [num, 회수]
        for(int num : nums) m[num]++;

        int max_value = -1;
        for(auto [key, value] : m){
            max_value = max(value, max_value);
        }

        int cnt = 0;
        for(auto [key, value] : m){
            if(value == max_value) cnt++;
        }

        return max_value * cnt;
    }
};