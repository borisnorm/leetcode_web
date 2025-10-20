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
   string NULL_NODE;
   string SEP;

public:

    // 7 [5 3, 4] [6 # 8]
    Codec(): NULL_NODE("#"), SEP(",") {}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    void serialize(TreeNode* root, stringstream& ss)
    {
        if (!root)
        {
          ss << NULL_NODE << SEP;
          return;
        }

        ss << root->val << SEP;

        serialize(root->left, ss);
        serialize(root->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
       stringstream ss(data);
       string item;
       list<string> nodes;

       while (getline(ss, item, ','))
         nodes.push_back(item);

       return deserialize(nodes);
    }

    TreeNode* deserialize(list<string>& nodes)
    {
       string node_str = nodes.front();
       nodes.pop_front();

       if (node_str == NULL_NODE)
         return nullptr;
        
       TreeNode* node = new TreeNode(stoi(node_str));

       node->left = deserialize(nodes);
       node->right = deserialize(nodes);

       return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));