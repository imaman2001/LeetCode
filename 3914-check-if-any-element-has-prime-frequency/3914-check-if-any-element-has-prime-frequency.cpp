class Solution {
    bool isPrime(int n){
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;

        for(int i=3; i*i<=n; i = i+2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        for(int i : nums){
            freq[i]++;
        }

        for(const auto& val : freq){
            if(isPrime(val.second)){
                return true;
            }
        }
        return false;
    }
};