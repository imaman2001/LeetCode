class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n; i++){
            int sum = 0;
            int num = i;

            while(num != 0){
                sum = sum + num % 2;    // remainder
                num = num / 2;          // quotient
            }

            ans.push_back(sum);
        }
        return ans;
    }
};