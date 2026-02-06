class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int>num3;
    //     for(int i=0; i<nums1.size(); i++){
    //         num3.push_back(nums1[i]);
    //     }
    //     for(int i=0; i<nums2.size(); i++){
    //         num3.push_back(nums2[i]);
    //     }

    //     sort(num3.begin() , num3.end());
        
    //     int final = num3.size();

    //     if(final % 2 == 1){
    //         return static_cast<double>(num3[final / 2 ]);
    //     } 
    //     else {
    //         int mid1 = num3[final / 2 - 1 ];
    //         int mid2 = num3[final / 2];
    //         return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0 ;
    //     }

    // }
// optimal solutio
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int ind1 = n/2;
        int ind2 = ind1 - 1;  // if ans is even we use this
        int count = 0;
        int ele1 = -1;
        int ele2 = -1;
        int i = 0, j = 0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                if(count == ind1) ele1 = nums1[i];
                if(count == ind2) ele2 = nums1[i];
                i++;
                count++;
            } else {
                if(count == ind1) ele1 = nums2[j];
                if(count == ind2) ele2 = nums2[j];
                j++;
                count++;
            }
        }
// find our ele1 and ele2 in rest of the elements
        while(i<n1){
            if(count == ind1) ele1 = nums1[i];
            if(count == ind2) ele2 = nums1[i];
            i++;
            count++;
        }
        while(j<n2){
            if(count == ind1) ele1 = nums2[j];
            if(count == ind2) ele2 = nums2[j];
            j++;
            count++;
        }

        //if n size is odd
        if(n%2 == 1){
            return (double)ele1;
        }

        return (double)((double)(ele1 + ele2)) / 2.0;
    }
};