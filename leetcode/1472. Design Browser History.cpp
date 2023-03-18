// Runtime 117 ms Beats 99.39%
// Memory 56.7 MB Beats 99.5%

class BrowserHistory {
public:
    int idx; // current index
    int len; // max history size
    vector<string> histories;
    BrowserHistory(string homepage) {
        histories.push_back(homepage);
        len = 1;
        idx = 0;
    }
    
    void visit(string url) {
        idx++;
        if(idx < (int)(histories.size())){
            histories[idx] = url;
            len = idx + 1;
        }
        else{
            len++;
            histories.push_back(url);
        }
    }
    
    string back(int steps) {
        // idx -= steps;
        // if(idx < 0) idx = 0;
        idx = max(0, idx - steps);
        return histories[idx];
    }
    
    string forward(int steps) {
        // idx += steps;
        // if(idx >= len) idx = len - 1;
        idx = min(len - 1, idx + steps);
        return histories[idx];
    }
};