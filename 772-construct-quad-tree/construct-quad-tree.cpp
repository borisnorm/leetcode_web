/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> prefixSum;

    int queryPrefixSum(int r1, int c1, int r2, int c2)
    {
       return prefixSum[r2][c2] - prefixSum[r1][c2] - prefixSum[r2][c1] + prefixSum[r1][c1];
    }
    Node* build(int r1, int c1, int r2, int c2)
    {
       int total = (r2-r1) * (c2-c1);
       int s = queryPrefixSum(r1, c1, r2, c2);

       if (s == 0)     // 全0 ,  叶节点
         return new Node(false, true);
      
       if (s == total) // 全1, 叶节点
         return new Node(true, true);

       int rm = (r1 + r2) / 2;  //行中点
       int cm = (c1 + c2) / 2;  //列中点
       
                        
       
       //  [0,0]
       //  [r1, c1]
       // r1 ___________________ r1
       //    |        |        |
       //    |        |[rm, cm]|
       // rm |________|________| [rm,c2]
       //    |        |        |
       //    |        |        |
       //    |________|________|
       //  r2 c1                [r2, c2]
       //
       // 行决定上下，列决定左右 
       // r, c 是 vector 的下标 
       //                   val 随意, 非叶子节点
       Node* node = new Node(true, false);
       node->topLeft = build(r1, c1, rm, cm);
       node->topRight = build(r1, cm, rm, c2);
       node->bottomLeft = build(rm, c1, r2, cm);
       node->bottomRight = build(rm, cm,  r2, c2);
       return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        prefixSum.assign(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; i++)
        {
           for (int j = 1; j <= n; j++)
              prefixSum[i][j] = grid[i-1][j-1] + 
                                prefixSum[i-1][j] + 
                                prefixSum[i][j-1] - 
                                prefixSum[i-1][j-1];
        }

        return build(0, 0, n, n);
    }
};