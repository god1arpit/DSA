class Solution {
public:
     bool isValid(const std::string& str) {
        int count =0;
        for(char c : str){
            if(c == '(')
            count++;
            else if(c ==')'){
                count--;
            if(count < 0)return false;
        }
        }
return count == 0;
    }
std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> res;
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;
        q.push(s);
        visited.insert(s);
       bool found = false;

       while(!q.empty()){
        std::string curr=q.front();
        q.pop();

        if(isValid(curr)){
            res.push_back(curr);
            found = true;
        }
        if(found)continue;
        for(int i =0;i<curr.size();++i){
            if(curr[i]!='(' && curr[i]!=')')continue;
            std::string next_str = curr.substr(0,i) + curr.substr(i+1);
            if(!visited.count(next_str)){
                visited.insert(next_str);
                q.push(next_str);
            }
        }

        }
        return res;
       }


};