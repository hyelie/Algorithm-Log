class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), less<int>());
        int s = 0, e = people.size()-1;
        int answer = 0;
        while(s<=e){
            int sum= people[e];
            e--; answer++;
            if(sum + people[s] <= limit){
                s++;
            }
        }
        return answer;
    }
};