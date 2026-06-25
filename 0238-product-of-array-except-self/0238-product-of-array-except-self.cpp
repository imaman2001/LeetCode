class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int>ans(arr.size());
        
        ans[0] = 1;

        for(int i=1; i<arr.size(); i++){
            ans[i] = ans[i-1] * arr[i-1];   // we get the last index value here
        }

        int prefix = 1;
        for(int i=arr.size()-2; i>=0; i--){
            // update prefix backward
            prefix *= arr[i+1];

            // update answer
            ans[i] *= prefix;
        }
        return ans;
    }
};