// O(n^2 * logn)
class Solution {
public:
    Node* DFS(int r, int c, int len, vector<vector<int>>& grid){
        bool isAllSame = true; int standard = grid[r][c];
        for(int i = r; i<r+len; i++){
            for(int j = c; j<c+len; j++){
                if(grid[i][j] != standard){
                    isAllSame = false;
                    i = r+len; j = c+len;
                }
            }
        }

        // exit condition
        if(isAllSame){
            Node* cur = new Node(grid[r][c], 1); // val: grid[r][c], isLeaf: true
            return cur;
        }

        // deeper
        Node* cur = new Node(0, 0); // val: any, isLeaf: false
        int halflen = len/2;
        cur->topLeft = DFS(r, c, halflen, grid);
        cur->topRight = DFS(r, c + halflen, halflen, grid);
        cur->bottomLeft = DFS(r + halflen, c, halflen, grid);
        cur->bottomRight = DFS(r + halflen, c + halflen, halflen, grid);
        return cur;
    }

    Node* construct(vector<vector<int>>& grid) {
        return DFS(0, 0, grid.size(), grid);
    }
};


// O(n^2)
class Solution {
public:
    Node* baseNode[2];
    Node* DFS(int r, int c, int len, vector<vector<int>>& grid){
        // base case
        if(len == 1) return baseNode[grid[r][c]]; // val : grid[r][c], isLeaf: true

        // deeper
        int halflen = len/2;
        Node* topLeft = DFS(r, c, halflen, grid);
        Node* topRight = DFS(r, c + halflen, halflen, grid);
        Node* bottomLeft = DFS(r + halflen, c, halflen, grid);
        Node* bottomRight = DFS(r + halflen, c + halflen, halflen, grid);

        // if all child has same value, then current must be leaf
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val){
            return baseNode[grid[r][c]]; // val: grid[r][c], isLeaf: true
        }
        else{
            return new Node(1, 0, topLeft, topRight, bottomLeft, bottomRight);
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        baseNode[0] = new Node(0, 1); // value 0, leaf node
        baseNode[1] = new Node(1, 1); // value 1, leaf node
        return DFS(0, 0, grid.size(), grid);
    }
};