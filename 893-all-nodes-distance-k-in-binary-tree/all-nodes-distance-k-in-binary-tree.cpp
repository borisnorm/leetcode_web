/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, nullptr, parent);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;
        while(!q.empty())
        {
          int q_size = q.size();
          if (dist == k)
          {
              vector<int> ans;
              while (!q.empty())
              {
                  ans.push_back(q.front()->val);
                  q.pop();
              }

              return ans;
          }

          for (int i = 0; i < q_size; i++)
          {
             TreeNode* cur = q.front();
             q.pop();

             if (cur->left && !visited.count(cur->left))
             {
                visited.insert(cur->left);
                q.push(cur->left);
             }

             if (cur->right && !visited.count(cur->right))
             {
                visited.insert(cur->right);
                q.push(cur->right);
             }

             auto it = parent.find(cur);
             if (it != parent.end() && it->second && !visited.count(it->second))
             {
                visited.insert(it->second);
                q.push(it->second);
             }
          }

          dist++;
        }

        return {};
    };

private:
  void buildParent(TreeNode* node, TreeNode* par,
                   unordered_map<TreeNode*, TreeNode*> & parent)
  {
     if (!node)
       return;
    
     parent[node] = par;

     buildParent(node->left, node, parent);
     buildParent(node->right, node, parent);
  }
};