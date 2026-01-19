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

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0/val});
        }

        vector<double> res;
        for (auto& q: queries)
        {
           unordered_set<string> visited;

           double ans = dfs(graph, q[0], q[1], visited);
           
           res.push_back(ans);
        }

        return res;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>>& graph,
               const string& cur, const string& target, unordered_set<string>& visited)
    {

        if (!graph.count(cur) || !graph.count(target))
           return -1.0;

        if (cur == target)
           return 1.0;

         visited.insert(cur);

        for (auto& [next, weight] : graph[cur])
        {
            if (visited.count(next))
              continue;

            double sub = dfs(graph, next, target, visited);
            if (sub != -1.0)
            {
                return sub * weight;
            }
        }
        
        // 没有关联的, 比如 a, b, c, d   a/b = 2, b/c= 2,  然后木诶呦 b/d 或是 c/d 的关系
        return -1.0;
    }
};