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
         visited.insert(cur);

        for (auto& [next, weight] : graph[cur])
        {
            if (visited.count(next))
              continue;

            //sub = (next / target)
            //(cur / target) = (cur / next) * (next / target)
            //               =     weight   * sub
            double sub = dfs(graph, next, target, visited);
            // 成功找到 target
            // 从 next → target 存在一条路径
            if (sub != -1.0)
            {
                return sub * weight;
            }
        }
        
        // 没有关联的, 比如 a, b, c, d   a/b = 2, b/c= 2,  然后木诶呦 b/d 或是 c/d 的关系
        //从 cur 出发， 遍历了所有 neighbor， 所有可能路径都尝试过， 仍然无法到达 target
        return -1.0;
    }
};