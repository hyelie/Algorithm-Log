// Runtime 2 ms Beats 91.83%
// Memory 7.7 MB Beats 85.40%

class Solution {
public:
    vector<int> dp;
    bool DFS(int i, string& s, vector<string>& wordDict){
        if(i == s.length()) return true;
        if(dp[i] != -1) return dp[i];

        for(string word : wordDict){
            int wordlen = word.length();
            if(s.substr(i, wordlen) == word){
                bool result = DFS(i + wordlen, s, wordDict);
                dp[i] = result;
                if(result) return result;
            }
        }
        dp[i] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length());
        fill(dp.begin(), dp.end(), -1);
        return DFS(0, s, wordDict);
    }
};

/*
dp[i] : i까지 봤을 때 만들 수 있는지
*/