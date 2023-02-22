// rumtime 60ms (beats 70.4%)
// memory 26MB (beats 77.7%)

class Solution {
public:
    // weight에 해당하는 무게를 days 안에 나눌 수 있는지
    bool isCarryable(vector<int>& weights, int weight, int days){
        int weightSize = weights.size(), i = 0;
        // days만큼 순회하면서 weights를 모두 들 수 있는지 검사
        while(days > 0 && i < weightSize){ // 실수 : days >= 0이라고 적음.
            int dayWeightSum = 0;
            // 더 들 수 있으면 더 듬
            while(i < weightSize && dayWeightSum + weights[i] <= weight){ // 실수 : dayWeightSum + weight[o] < weight라고 적음.
                dayWeightSum += weights[i];
                i++;
            }
            days--; // 날짜 종료
        }
        if(i < weightSize) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()), end = start * weights.size();

        while(start < end){
            int mid = start + (end - start) / 2;
            if(isCarryable(weights, mid, days)){ // 옮길 수 있으면 무게를 더 줄여도 됨
                end = mid;
            }
            else start = mid + 1; // 옮길 수 없다면 무게를 늘려야 함.
        }

        return end;
    }
};