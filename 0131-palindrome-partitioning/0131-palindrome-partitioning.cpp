class Solution {
public:
    bool isPalindrome(string s, int st, int end){
        while(st<=end){
            if(s[st++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void func(int idx, string s, vector<string>& path, vector<vector<string>>& ans){
        if(idx == s.length()){
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                func(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        func(0, s, path, ans);
        return ans;
    }
};