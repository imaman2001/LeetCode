class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     int left = 0;
    //     int maxl = 0;
    //     unordered_set<char> charSet;
    //     for(int i = 0; i  < s.length(); i++){
    //         while(charSet.find(s[i]) != charSet.end()){
    //           charSet.erase(s[left]);
    //            left++;
    //         }
    //         charSet.insert(s[i]);
    //         maxl = max(maxl , i-left+1);
    //     }
    //     return maxl;
    // }

    // int lengthOfLongestSubstring(string s) {
    //     int left = 0;
    //     int n = s.length();
    //     int maxLen = 0;
    //     unordered_set<char> charSet;

    //     for(int i=0; i<n; i++){
    //         while(charSet.find(s[i]) != charSet.end()){
    //             charSet.erase(s[left]);
    //             left++;
    //         }

    //         charSet.insert(s[i]);
    //         maxLen = max(maxLen , i - left + 1);
    //     }
    //     return maxLen;
    // }

// optimal solution
    int lengthOfLongestSubstring(string s){
        vector<int> mpp(256, -1);
        int left = 0;
        int right = 0;
        int n = s.length();
        int maxLen = 0;

        while(right < n){
            if(mpp[s[right]] != -1){
                left = max(left , mpp[s[right]] + 1);
            }

            mpp[s[right]] = right;
            maxLen = max(maxLen , right-left+1);
            right++;
        }
        return maxLen;
    }
};