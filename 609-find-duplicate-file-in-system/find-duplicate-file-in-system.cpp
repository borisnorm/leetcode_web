class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        //            content,  path vector for duplicate 
        unordered_map<string, vector<string>> content2path;
        
        for (string& path_str: paths)
        {
          stringstream ss(path_str);
          string dir;
          //默认使用 空格作为 分割符, 直接分割出 path 出来
          //后面的就是文件名 与 文件 content
          ss >> dir;

          string fileInfo;
          while(ss >> fileInfo)
          {
             int left = fileInfo.find('(');
             int right = fileInfo.find(')');
            
             // substr[L, r), '(' 就是它的的 r
             string fileName = fileInfo.substr(0, left);
             string fileContent = fileInfo.substr(left+1, right-left-1);

             string fullPath = dir + '/' + fileName;
             content2path[fileContent].push_back(fullPath);  
          }
        }

        vector<vector<string>> res;
        for(auto& [content, path_grp]: content2path)
        {
          if (path_grp.size() > 1)
            res.push_back(path_grp);
        }
        
        return res;
    }
};