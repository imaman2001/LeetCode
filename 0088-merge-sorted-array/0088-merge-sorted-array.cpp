class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int len = nums1.size();
        // if(n == 0) return ;
        // int eIdx = len - 1;
        // while(n > 0 && m > 0){
        //     if(nums2[n-1] >= nums1[m-1]){
        //         nums1[eIdx] = nums2[n-1];
        //         n--;
        //     } else {
        //         nums1[eIdx] = nums1[m-1];
        //         m--;
        //     }
        //     eIdx--;
        // }
        // while(n>0){
        //     nums1[eIdx] = nums2[n-1];
        //     n--;
        //     eIdx--;
        // }



        //2nd Approach

        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin() , nums1.end());
    }
};