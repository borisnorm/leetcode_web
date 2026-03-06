/*
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i=0; i < n; i++)
        {
           string a = equations[i][0];
           string b = equations[i][1];
           double val = values[i];

           graph[a].push_back({b, val});
           graph[b].push_back({a, 1.0/val});
        }

        vector<double> res;
        for (auto& query: queries)
        {
           string start = query[0];
           string end   = query[1];
          
           if (!graph.count(start) || !graph.count(end))
           {
              res.push_back(-1.0);
              continue;
           }  
           
           if (start == end)
           {
              res.push_back(1.0);
              continue;
           }

           unordered_set<string> visited;
           queue<pair<string, double>> q;
           q.push({start, 1.0});
           visited.insert(start);

           double ans = -1.0;
           while(!q.empty())
           {
              auto [cur, cur_weight] = q.front();
              q.pop();

              
              if(cur == end)
              {
                 ans = cur_weight;
                 break;
              }

              for (auto [next, nxt_weight]: graph[cur])
              {
                  if (visited.count(next))
                    continue;

                  // string      string
                  //   a  ----->   b * weight

                  // find -> c 
                  // a/b =  w1,  b/c = w2  quesiton: a/c
                  // 
                  visited.insert(next);
                  
                  //不需要这个 check 是因为在 建图的时候, a->b, b->a, 所以必然存在 不需要检查
                  //if (graph.count(next))
                  {
                    q.push({next, nxt_weight * cur_weight});
                  }
              }
           }

           res.push_back(ans);
        }

        return res;
    }
};
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();

        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i  = 0; i < n; i++)
        {
            auto equation = equations[i];

            string a = equation[0];
            string b = equation[1];
            double val = values[i];

            // a = b/val
            // 因此图里必须有两条边：
            // a -> b   weight = 2
            // b -> a   weight = 1/2
            graph[a].push_back({b, val});

            // b = a/val
            graph[b].push_back({a, 1.0/val});
        }

        vector<double> res;
        for (auto& q: queries)
        {
           string start = q[0];
           string end   = q[1];

           unordered_set<string> visited;
           visited.insert(start);
           double ans = dfs(graph, start, end, visited);
           
           res.push_back(ans);
        }

        return res;
    }
    
    //                          a,                 b,    weight
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph,
               const string& cur, const string& target, unordered_set<string>& visited)
    {
        // check target 是否存在 
        if (!graph.count(cur) || !graph.count(target))
           return -1.0;

        // dfs 的终止条件
        if (cur == target)
           return 1.0;

         //相当于染色
        // visited.insert(cur);

        for (auto& [next, weight] : graph[cur])
        {
            if (visited.count(next))
              continue;

            visited.insert(next);
            //sub = (next / target)
            //(cur / target) = (cur / next) * (next / target)
            //               =     weight   * sub
            double sub = dfs(graph, next, target, visited);
            // 成功找到 target
            // 从 next → target 存在一条路径
            if (sub != -1.0)
            {
                // 返回的是 边权 累乘
                // a/b = w1, b/c = w2
                // a/c = a/b * b/c = w1 * w2; 
                return sub * weight;
            }
        }
        
        // 没有关联的, 比如 a, b, c, d   a/b = 2, b/c= 2,  然后木诶呦 b/d 或是 c/d 的关系
        //从 cur 出发， 遍历了所有 neighbor， 所有可能路径都尝试过， 仍然无法到达 target
        return -1.0;
    }
};
