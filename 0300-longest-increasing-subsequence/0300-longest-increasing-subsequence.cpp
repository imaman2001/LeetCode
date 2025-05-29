class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        // store all unique elements
        unordered_set<int> s(arr.begin() , arr.end());
        // store into another array
        vector<int> arr2(s.begin(), s.end());
        // sort 2nd array 
        sort(arr2.begin() , arr2.end());

        int n = arr.size();
        int m = arr2.size();

        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

    // same logic as longest common substring/subsequence
        for(int i=1; i<n+1; i++){       // i takes the arr1 size
            for(int j=1; j<m+1; j++){   // j takes the arr2 size

                // if arr1 and arr2 last ele is same 
                if(arr[i-1] == arr2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};