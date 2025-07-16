class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countEven = 0, countOdd = 0;
        for(int num : nums){
            if(num % 2 == 1){
                countOdd++;
            } else {
                countEven++;
            }
        }

        int dpEven = 0, dpOdd = 0;
        for(int num : nums){
            if(num % 2 == 0) dpEven = max(dpEven, dpOdd + 1);
            else dpOdd = max(dpOdd , dpEven + 1);
        }

        return max({countEven , countOdd, dpEven, dpOdd});
    }
};