// Runtime 2398 ms Beats 13.14%
// Memory 349.3 MB Beats 92.50%

class TrieNode{
public:
    bool isEnd;
    map<char, TrieNode*> childs;
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        for(char c : word){
            if(cur->childs.find(c) == cur->childs.end()){
                TrieNode *next = new TrieNode();
                cur->childs[c] = next;
            }
            cur = cur->childs[c];
        }
        cur->isEnd = true;
    }

    bool searchHelper(string word, TrieNode *cur){
        for(int i = 0; i<word.size(); i++){
            if(word[i] != '.'){
                if(cur->childs.find(word[i]) == cur->childs.end()) return false;
                cur = cur->childs[word[i]];
            }
            else{
                for(auto [key, value] : cur->childs){
                    if(searchHelper(word.substr(i+1), value)) return true;
                }
                return false;
            }
        }
        if(cur->isEnd) return true;
        else return false;
    }
    
    bool search(string word) {
        return searchHelper(word, root);
    }
};