class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>ans1;
        vector<char>ans2;
        int n = max(s.size(), t.size());

        
        for(char ch : s){

            if(ch == '#'){
                if(!ans1.empty()){
                    ans1.pop_back();
                }
            } else{
                ans1.push_back(ch);
            }
        }

        for(char ch : t){

            if(ch == '#'){
                if(!ans2.empty()){
                    ans2.pop_back();
                }
            } else{
                ans2.push_back(ch);
            }

        }

        if(ans1.size() != ans2.size()) return false;
        for(int i=0; i<ans1.size(); i++){
            if(ans1[i] != ans2[i]){
                return false;
            }
        }
        return true;
    }
};