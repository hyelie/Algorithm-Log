// Runtime 0 ms Beats 100%
// Memory 7 MB Beats 98.74%

typedef long long ll;
class Solution {
public:
    double average(vector<int>& salary) {
        ll sum = 0, minValue = INT_MAX, maxValue = INT_MIN;
        for(int s : salary){
            minValue = min(minValue, (ll)s);
            maxValue = max(maxValue, (ll)s);
            sum += s;
        }
        sum = sum - minValue - maxValue;
        return (double)sum / (salary.size() - 2);
    }
};