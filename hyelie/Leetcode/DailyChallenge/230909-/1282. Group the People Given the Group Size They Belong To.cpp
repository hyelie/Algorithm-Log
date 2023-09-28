// Runtime 22 ms Beats 8.50% 
// Memory 15.3 MB Beats 5.29%

class Solution {
public:
    map<int, vector<vector<int>>> groupMap; // groupMap[i] : i명짜리 group
    // i번째 사람을 groupSize 크기의 group에 넣는 함수
    void insertIntoGroup(int i, int groupSize){
        // 아직 해당 size의 group이 없는 경우 - 생성
        if(groupMap.find(groupSize) == groupMap.end()){
            vector<int> newGroup(1, i);
            groupMap[groupSize].push_back(newGroup);
            return;
        }

        // 해당 size의 group이 있는 경우
        // 1. group이 있지만 아직 그만큼 차지 못한 경우
        // 2. 기존에 존재하는 group size가 groupSize여서 새로운 group을 만들어야 하는 경우
        vector<int> &lastGroup = groupMap[groupSize].back();
        
        // case 2
        if(lastGroup.size() == groupSize){
            vector<int> newGroup(1, i);
            groupMap[groupSize].push_back(newGroup);
        }
        // case 1
        else{
            lastGroup.push_back(i);
            // groupMap[groupSize].back().push_back(i);
        }
        
    }
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int len = groupSizes.size();
        for(int i = 0; i<len; i++){
            insertIntoGroup(i, groupSizes[i]);
        }

        vector<vector<int>> answer;
        for(auto &[groupSize, groups] : groupMap){
            for(vector<int> group : groups){
                answer.push_back(group);
            }
        }
        return answer;
    }
};

// Runtime 12 ms Beats50.27% 
// Memory 13.4 MB Beats 37.1%

class Solution {
public:
    map<int, vector<int>> groupMap; // groupMap[i] : i size짜리 group
    vector<vector<int>> answer;
    // i번째 사람을 groupSize 크기의 group에 넣는 함수
    void insertIntoGroup(int i, int groupSize){
        // 아직 해당 size의 group이 없는 경우 - 생성
        if(groupMap.find(groupSize) == groupMap.end()){
            vector<int> newGroup(0);
            groupMap[groupSize] = newGroup;
        }

        // 해당 size의 group이 있는 경우 - 거기다가 넣음.
        vector<int> &group = groupMap[groupSize]; // groupSize짜리 group
        group.push_back(i);

        if(groupSize == group.size()){
            answer.push_back(group);
            vector<int> newGroup(0);
            group = newGroup;
        }
    }
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int len = groupSizes.size();
        for(int i = 0; i<len; i++){
            insertIntoGroup(i, groupSizes[i]);
        }
        return answer;
    }
};