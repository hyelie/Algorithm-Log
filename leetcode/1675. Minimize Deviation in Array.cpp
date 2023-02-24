// runtime 352ms (beats 84.75%)
// memory 89MB (beats 43.22%)

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int num : nums){
            s.insert(num & 1 ? num * 2 : num);
        }

        if(s.size() == 1) return 0;
    
        int answer = *s.rbegin() - *s.begin();
        while(!(*s.rbegin() & 1)){
            int last = *s.rbegin();
            s.erase(last);
            s.insert(last / 2);
            if(s.size() == 1) return 0;
            answer = min(answer, *s.rbegin() - *s.begin());
        }
        return answer;
    }
};