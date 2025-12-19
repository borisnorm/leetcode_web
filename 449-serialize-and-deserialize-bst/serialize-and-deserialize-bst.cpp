/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out; 
        preorder(root, out);
        if (!out.empty() && out.back() == ' ' )
          out.pop_back();
        
        return out;
    }

    void preorder(TreeNode* node, string& out)
    {
         if (!node)
           return;
        
         out += to_string(node->val);
         out.push_back(' ');

         preorder(node->left, out);
         preorder(node->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre = parse(data);
        int idx = 0;
        return build(pre, idx, LLONG_MIN, LLONG_MAX);
    }

    vector<int> parse(const string& s)
    {
       vector<int> res;
       if (s.empty())
         return res;
       
       stringstream ss(s);

       long long x;
       while (ss >> x)
         res.push_back((int)x);
        
       return res;
    }

    TreeNode* build(const vector<int> & pre, int& idx, long long low, long long high)
    {
        if (idx >= (int)pre.size())
          return nullptr;

        long long val = pre[idx];
        if (val <= low || val >= high)
          return nullptr;
        
        TreeNode* node = new TreeNode(val);
        idx++;

        node->left = build(pre, idx, low, val);
        node->right = build(pre, idx, val, high);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;