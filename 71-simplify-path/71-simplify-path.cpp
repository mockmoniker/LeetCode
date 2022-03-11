class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories = {};
        
        
        for(int i = 0; i < path.length(); ++i){
            // skip extra slashes
            while(i < path.length() and path[i] == '/'){
                ++i;
            }
            
            // get next dir
            string curr_dir = "";
            while(i < path.length() and path[i] != '/'){
                curr_dir.push_back(path[i]);
                ++i;
            }
            
            // don't add empty directories
            if(curr_dir == ""){
                continue;
            }
            
            // don't add single periods
            if(curr_dir == "."){
                continue;
            }
            
            // remove previous dir on double periods
            if(curr_dir == ".."){
                if(directories.size() > 0){
                    directories.pop_back();
                }
                continue;
            }
            
            // add dir
            directories.push_back(curr_dir);
        }
        
        // if root
        if(0 == directories.size()){
            return "/";
        }
        
        string absolute_path = "";
        for(int i = 0; i < directories.size(); ++i){
            absolute_path = absolute_path + "/" + directories[i];
        }
        
        return absolute_path;
    }
};