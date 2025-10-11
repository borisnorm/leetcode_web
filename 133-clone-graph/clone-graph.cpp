/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cloned_graph_map;
    Node* cloneGraph(Node* node) {
      if (!node)
        return node;
    
      return dfs(node);
    }

    Node* dfs(Node* node)
    {
      if (cloned_graph_map[node])
        return cloned_graph_map[node];
       
      Node* cloned_node = new Node(node->val);
      cloned_graph_map[node] = cloned_node;

      for (Node* neighbor: node->neighbors)
      {
         cloned_node->neighbors.push_back(dfs(neighbor));
      }

      return cloned_node;
    }

};