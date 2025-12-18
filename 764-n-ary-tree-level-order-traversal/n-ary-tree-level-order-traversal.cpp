/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
          return {};

        queue<Node*> q;
        q.push(root);

        vector<vector<int>> res;

        while (!q.empty())
        {
           int q_size = q.size();
           vector<int> level;
           for (int i = 0; i < q_size; i++)
           {
              Node* cur = q.front();
              q.pop();

              level.push_back(cur->val);

              for (Node* node: cur->children)
              {
                if (node)
                  q.push(node);
              }
           }

           res.push_back(level);
        }

        return res;
    }
};