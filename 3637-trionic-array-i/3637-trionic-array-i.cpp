class Solution {
public:
    // bool isTrionic(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n < 4) return false;
    //     int st=0;
    //     for(int i=0; i<n-1; i++){
    //         if(st == 0){
    //             if(nums[i] < nums[i+1]){    

    //             } else if(i > 0 && nums[i] > nums[i+1]){
    //                 st = 1;
    //             } else{
    //                 return false;
    //             }
    //         } else if(st == 1){
    //             if(nums[i] > nums[i+1]){

    //             } else if(nums[i] < nums[i+1]){
    //                 st = 2;
    //             } else {
    //                 return false;
    //             }
    //         } else if(st == 2){
    //             if(nums[i] < nums[i+1]){

    //             } else {
    //                 return false;
    //             }
    //         }
    //     }
    //     return st == 2;    
    // }

    bool isTrionic(vector<int>& nums){
        
        int i=1;
        int p=-1,q=-1,r=-1;

        while(i<nums.size() && nums[i-1] < nums[i]){
            p=i;
            i++;
        }

        while(i<nums.size() && nums[i-1] > nums[i]){
            q=i;
            i++;
        }

        while(i<nums.size() && nums[i-1] < nums[i]){
            r=i;
            i++;
        }

        if(i != nums.size() || p==-1 || q==-1 || r==-1){
            return false;
        }
       
        return true;
    }
};