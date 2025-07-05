class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num : arr){
            freq[num]++;
        }

        int lucky = -1;

        for(pair<int,int> p : freq){
            if(p.first == p.second){
                lucky = max(lucky , p.first);
            }
        }
        return lucky;
    }
};