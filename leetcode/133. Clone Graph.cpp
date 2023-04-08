// Runtime 9 ms Beats 23.26%
// Memory 8.8 MB Beats 65.38%

class Solution {
public:
    Node* copyroot;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        queue<Node*> q;
        set<Node*> visited;
        map<int, Node*> m; // mapper of clone node 

        q.push(node);
        visited.insert(node);
        while(!q.empty()){
            Node* origin = q.front(); q.pop();
            visited.insert(origin);

            if(m.find(origin->val) == m.end()){
                m[origin->val] = new Node(origin->val);
            }

            for(Node* adj : origin->neighbors){
                if(visited.find(adj) == visited.end()){
                    q.push(adj);
                }
            }                        
        }

        q.push(node);
        visited.clear();
        visited.insert(node);
        while(!q.empty()){
            Node* origin = q.front(); q.pop();
            visited.insert(origin);

            for(Node* adj : origin->neighbors){
                if(visited.find(adj) == visited.end()){
                    m[origin->val]->neighbors.push_back(m[adj->val]);
                    m[adj->val]->neighbors.push_back(m[origin->val]);
                    q.push(adj);
                }
            }                        
        }

        return m[1];
    }
};

// Runtime 7 ms Beats 61.34%
// Memory 8.8 MB Beats 53.37%

class Solution {
public:
    Node* copyroot;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        queue<Node*> q;
        set<Node*> visited;
        map<int, Node*> m; // mapper of clone node 

        q.push(node);
        visited.insert(node);
        while(!q.empty()){
            Node* origin = q.front(); q.pop();
            visited.insert(origin);

            if(m.find(origin->val) == m.end()){
                m[origin->val] = new Node(origin->val);
            }

            for(Node* adj : origin->neighbors){
                if(m.find(adj->val) == m.end()){
                    m[adj->val] = new Node(adj->val);
                    q.push(adj);
                }
                m[origin->val]->neighbors.push_back(m[adj->val]);
            }                        
        }

        return m[1];
    }
};

// Runtime 7 ms Beats 61.34%
// Memory 8.7 MB Beats 65.38%

class Solution {
public:
    Node* copyroot;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        queue<Node*> q;
        map<int, Node*> m; // mapper of clone node 

        if(m.find(node->val) == m.end()){
            m[node->val] = new Node(node->val);
        }

        q.push(node);
        while(!q.empty()){
            Node* origin = q.front(); q.pop();

            for(Node* adj : origin->neighbors){
                if(m.find(adj->val) == m.end()){
                    m[adj->val] = new Node(adj->val);
                    q.push(adj);
                }
                m[origin->val]->neighbors.push_back(m[adj->val]);
            }                        
        }

        return m[1];
    }
};