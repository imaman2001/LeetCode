class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        if(n == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int l = m-1;
        int r = n-1;
        int ans=0;
        while(l>=0 && r>=0){
            if(g[l] <= s[r]){
                ans++;
                r--;
                l--;
            } else{
                l--;
            }
        }
        return ans;
    }
};