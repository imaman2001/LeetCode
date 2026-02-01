class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>number;
        int fact = 1;
        for(int i=1; i<n; i++){
            fact = fact * i;        // 6
            number.push_back(i);
        }
        number.push_back(n);    // 1,2,3,4

        k = k-1;    //16, 
        string ans = "";
        while(true){
            ans = ans + to_string(number[k/fact]);  // find and insert into ans
            number.erase(number.begin() + k/fact);  // erase the index of element and also value and decrease the size also here by 1

            if(number.size() == 0) break;

            k = k % fact;   // 4
            fact = fact / number.size();    //2
        }
        return ans;
    }
};