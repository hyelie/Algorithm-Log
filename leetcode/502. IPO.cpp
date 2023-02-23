struct project{
    int profit, capital;
};

// bool cmp(project &a, project &b){
//         if(a.capital == b.capital){
//             return a.profit < b.profit;
//         }
//         return a.capital < b.capital;
// }

// get largest profit. if same profit, then get smaller capital
struct pqcmp{
    bool operator() (project &a, project &b) const{
        if(a.profit == b.profit){
            return a.capital > b.capital;
        }
        else return a.profit < b.profit;
    }
};

class Solution {
public:
    // int getUpperBound(int weight, vector<project>& projects, int previdx){
    //     int start = previdx, end = projects.size();
    //     int mid;
    //     while(start < end){
    //         mid = start + (end - start) / 2;
    //         if(projects[mid].capital > weight){ // must search backward
    //             end = mid;
    //         }
    //         else{ // must search forward
    //             start = mid + 1;
    //         }
    //     }
    //     return end;
    // }
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capitals) {
        int n = profits.size();
        
        // initialize projects
        vector<project> projects(n); // .first : profit, .second : capital
        for(int i = 0; i<n; i++){
            projects[i].profit = profits[i];
            projects[i].capital = capitals[i];
        }
        sort(projects.begin(), projects.end(), cmp); // order by ascending capital

        int answer = 0, previdx = 0;
        priority_queue<project, vector<project>, pqcmp> pq;
        while(k--){
            // get upper bound of w
            // 굳이 binary search를 쓸 필요가 없네?
            // int ubidx = getUpperBound(w, projects, previdx);
            // for(int i = previdx; i<ubidx; i++){ // insert on pq
            //     pq.push(projects[i]);
            // }
            // previdx = ubidx; // update previdx

            // push all projects to pq which its capital is less than w.
            // this can be linear, cause projects vector is sored by capital ascending.
            while(previdx < n && projects[previdx].capital <= w){
                pq.push(projects[previdx]);
                previdx++;
            }

            // get largest profit
            if(!pq.empty()){
                w += pq.top().profit;
                pq.pop();
            }
            else return w;
            
        }
        return w;
    }
};

/*
k개의 프로젝트를 끝낼 수 있음
total capital maximize
w원 있음.
profit[i] : 순수익
capital[i] : 시작하기 위한 자본

[profit] 오름차순 정렬
[capital] 오름차순 정렬

nlogn으로 풀어야 할 것.
1. capital로 오름차순 정렬, 매 탐색 시 capital보다 작은 것 중 profit이 제일 큰 것을 빼내야 함.

2. capital 정렬. w는 항상 monotonic increasing임을 보장받음.
k번 탐색을 할 거고, 각 iteration에서 정렬된 capital을 binary search, upper bound of w
직전 탐색의 index를 두고, 그 index부터 upper bound - 1까지 전부다 pq에 넣음. previdx 갱신

2. 
*/