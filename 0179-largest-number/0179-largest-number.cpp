class Solution {
public:
    static bool compare(string a, string b){
        string sa = a+b;
        string sb = b+a;
        return sa > sb;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> st;
        string ans = "";
        int n = nums.size();

        for(auto i : nums){
            st.push_back(to_string(i));
        }

        sort(st.begin(), st.end(), compare);

        if(st[0] == "0") return "0";

        for(auto i : st){
            ans += i;
        }

        return ans;
    }
};