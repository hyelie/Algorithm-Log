// Runtime 315 ms Beats 60.42%
// Memory 117.7 MB Beats 69.44%

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> answer(n), LIS;

        LIS.push_back(obstacles[0]);
        answer[0] = 1;
        for(int i = 1; i<n; i++){
            if(LIS.back() <= obstacles[i]){ // LIS 늘이는 경우
                LIS.push_back(obstacles[i]);
                answer[i] = LIS.size();
            }
            else{ // 중간에 넣을 수 있는 경우
                int start = 0, end = LIS.size()-1; // lower bound
                while(start < end){
                    int mid = (start + end) / 2;
                    if(obstacles[i] < LIS[mid]){ // 앞으로 당김
                        end = mid;
                    }
                    else{
                        start = mid + 1;
                    }
                }        
                // end = upper_bound(LIS.begin(), LIS.end(), obstacles[i]); 
                LIS[end] = obstacles[i];
                answer[i] = end + 1;
            }
        }
        return answer;
    }
};


/*
i까지 진행하면서 모든 obstacle에 대해 longest course length를 저장해 두면 될 듯.
그러면 어떤 i번째를 볼 때 upper bound idx - 1의 length + 1을 하면 되니까.

set을 쓸지, map을 쓸지? 정렬된 상태를 유지해야 하니까..

결국 LIS인데, 모든 index에 대해 이를 알아야 함
그럼 쉽지
대신 기존 LIS는 strictly increasing인 반면 여기서는 monotonic increasing이므로 이를 반영해야 함
LIS 늘이는 경우는 obstacles[i]가 크거나 같은 경우이고
중간에 넣을 때도 가능하면 뒤에 넣어야 하니까 upper bound를 바꾸는 식으로 해야 함
*/