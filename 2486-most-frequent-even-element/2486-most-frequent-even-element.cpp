class Solution{
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int maxFreq = 0;

        map<int, int> mp;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                mp[nums[i]]++;
            }
        }
        for(auto el : mp){
            if(el.second > maxFreq){
                maxFreq = el.second;
                ans = el.first;
            }
        }
        return ans;
    }
};