class TrieNode{
public:
    map<char, TrieNode*> next;
    bool isEnd;
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(char c : word){
            if(cur->next.find(c) == cur->next.end()){
                TrieNode *child = new TrieNode();
                cur->next[c] = child;
            }
            cur = cur->next[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(char c : word){
            if(cur->next.find(c) == cur->next.end()) return false;
            cur = cur->next[c];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(char c : prefix){
            if(cur->next.find(c) == cur->next.end()) return false;
            cur = cur->next[c];
        }
        return true;
    }
};