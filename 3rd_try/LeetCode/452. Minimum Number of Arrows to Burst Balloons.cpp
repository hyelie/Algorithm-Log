bool cmp(vector<int>& a, vector<int>& b){ // end 오름차, start 오름차
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

typedef long long ll;
    
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        ll cnt = 0;
        ll cur_pos = LONG_MIN;
        ll i = 0;
        while(1){
            if(i >= points.size()) break;

            if(cur_pos < points[i][0]){
                cur_pos = points[i][1];
                cnt++;
                i++;
            }
            else{
                i++;
            }
        }

        return cnt;
    }
};