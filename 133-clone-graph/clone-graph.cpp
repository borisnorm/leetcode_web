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
// clone graph 的核心是在 构造 nei 关系的时候, cur 与  nei 必须同时存续, 否则就会 漏边, 关系是双向的
// 而 unordered_map 可以帮助我们破解 建立关系中的循环依赖问题
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
          return nullptr;
        
        unordered_map<Node*, Node*> cur2cpy;
        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* cur = q.front();
            q.pop();
        
            if (!cur2cpy.count(cur))
               cur2cpy[cur] = new Node(node->val);
            Node* cloned_node = cur2cpy[cur];

            for (Node* nei : cur->neighbors)
            {
               if (!cur2cpy.count(nei))
               {
                  cur2cpy[nei] = new Node(nei->val);
                  q.push(nei);
               }
               Node* cloned_nei = cur2cpy[nei];
               cloned_node->neighbors.push_back(cloned_nei);
            }
        }

        return cur2cpy[node];
    }
};
/*
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
          return nullptr;

        unordered_map<Node*, Node*> cur2clone;
    
       //不必这么写, cloned_node 在内部 while 循环中使用
       // dfs 这么写完全是为了 返回 原始 root node
       // Node* cloned_node = new Node(node->val);
       // cur2clone[node] = cloned_node;

       cur2clone[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
           Node* cur = q.front();
           q.pop();

           Node* cloned_node = cur2clone[cur];

           for (Node* nei: cur->neighbors)
           {
              if (!cur2clone.count(nei))
              {
                cur2clone[nei] = new Node(nei->val);
                q.push(nei);
              }

              cloned_node->neighbors.push_back(cur2clone[nei]);
           }
        }

        return cur2clone[node];
    }
};
*/

/*
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
          return nullptr;

        unordered_map<Node*, Node*> cur2clone;

        return dfs(node, cur2clone);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& cur2clone)
    {
        if (!node)
          return nullptr;
        
        if (cur2clone.count(node))
          return cur2clone[node];
        
        Node* cloned_node = new Node(node->val);
        cur2clone[node] = cloned_node;

        for (Node* nei : node->neighbors)
        {
           cloned_node->neighbors.push_back(dfs(nei, cur2clone));
        }

        return cloned_node;
    }
};

*/


/*
class Solution {
public:
unordered_map<Node*, Node*> cur2clone;
    Node* cloneGraph(Node* node) {
        if (!node)
          return nullptr;
        return dfs(node);
    }

    Node* dfs(Node* node)
    {
        if (!node)
          return nullptr;
        
        if (cur2clone.count(node))
          return cur2clone[node];
        
        Node* cloned_node = new Node(node->val);
        cur2clone[node] = cloned_node;

        for (Node* nei : node->neighbors)
        {
           cloned_node->neighbors.push_back(dfs(nei));
        }

        return cloned_node;
    }
};
*/


/*
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

      //遍历 cur 的 neibor, 给clone设置 neibor
      for (Node* neighbor: node->neighbors)
      {
         cloned_node->neighbors.push_back(dfs(neighbor));
      }

      return cloned_node;
    }

};
*/