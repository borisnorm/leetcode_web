/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
          vector<int> list1;
          vector<int> list2;
          preOrderTraverse(root1, list1);
          preOrderTraverse(root2, list2);

          vector<int> res;

          int m = list1.size();
          int n = list2.size();
          int i = 0;
          int j = 0;

          while (i < m && j < n)
          {
              if (list1[i] < list2[j])
              {
                  res.push_back(list1[i]);
                  i++;
              }
              else
              {
                  res.push_back(list2[j]);
                  j++;
              }
          }

          while (i < m)
          {
              res.push_back(list1[i]);
              i++;
          }

          while (j < n)
          {
             res.push_back(list2[j]);
             j++;
          }

         return res;
    }

    void preOrderTraverse(TreeNode* node, vector<int>& treelist)
    {
        if (!node)
          return;
        
        preOrderTraverse(node->left, treelist);
        treelist.push_back(node->val);
        preOrderTraverse(node->right, treelist);
    }
};