class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cur = 0;
        for(int i = 0; i<n;){
            int end = i; // end : chars[i]와 같은 마지막 index
            while(end + 1< n && chars[i] == chars[end + 1]){
                end++;
            }

            // get compressed string
            string str = ""; str += chars[i];
            if(i != end){
                str += to_string(end - i + 1);
            }
            i = end + 1;

            // replace
            for(char c : str){
                chars[cur] = c;
                cur++;
            }
        }
        chars.erase(chars.begin() + cur, chars.end());
        return chars.size();
    }
};
