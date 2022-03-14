class Solution {
public:
    string simplifyPath(string path) {
        string_view a_path(path);
        deque<string> c_path;
        while(!a_path.empty()){
            int n_of_slashes = (a_path.find_first_not_of('/'));
            if(n_of_slashes == a_path.npos) break;
            a_path.remove_prefix(n_of_slashes);
            int possible_token_size = a_path.find_first_of('/');
            int token_size = (possible_token_size != a_path.npos) ? possible_token_size : a_path.size();
            string_view tkn = a_path.substr(0, token_size);
            string token(tkn);
            if(token == ".." && !c_path.empty()) c_path.pop_back();
            else if(token != "." && token != "..") c_path.push_back(token);
            a_path.remove_prefix(token_size);
        }
        string can_path;
        for(int i = 0; i < c_path.size(); ++i){
            can_path.insert(can_path.size(), ("/" + c_path[i]));
        }
        if(can_path == "") can_path.append(1, '/');
        return can_path;
    }
};