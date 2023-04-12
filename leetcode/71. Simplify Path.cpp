// Runtime 8 ms Beats 46.38%
// Memory 9.3 MB Beats 70.22%

class Solution {
public:
    string simplifyPath(string path) {
        // parse by '/'
        vector<string> directories;
        istringstream iss(path);
        string buffer;
        while(getline(iss, buffer, '/')) directories.push_back(buffer);
        
        // use stack. pop and push.
        vector<string> canonical;
        for(string directory : directories){
            if(directory == "" || directory == ".") continue;
            else if(directory == ".."){
                if(!canonical.empty()) canonical.pop_back();
            }
            else canonical.push_back(directory);
        }

        string answer = "/";
        for(int i = 0; i<canonical.size(); i++){
            answer += canonical[i] + (i == canonical.size()-1 ? "" : "/");
        }
        return answer;
    }
};