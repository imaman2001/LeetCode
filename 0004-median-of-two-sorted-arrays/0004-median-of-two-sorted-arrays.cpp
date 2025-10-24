class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>num3;
        for(int i=0; i<nums1.size(); i++){
            num3.push_back(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++){
            num3.push_back(nums2[i]);
        }

        sort(num3.begin() , num3.end());
        
        int final = num3.size();

        if(final % 2 == 1){
            return static_cast<double>(num3[final / 2 ]);
        } 
        else {
            int mid1 = num3[final / 2 - 1 ];
            int mid2 = num3[final / 2];
            return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0 ;
        }

    }
};