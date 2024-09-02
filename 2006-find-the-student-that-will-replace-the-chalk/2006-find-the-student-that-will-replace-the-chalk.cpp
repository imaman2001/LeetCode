class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long sum = 0;
       for(int i : chalk){
        sum += i;
       }
       int remain = k % sum;

       for(int j=0; j<chalk.size(); j++){
        if(remain < chalk[j]){
            return j;
        }
        remain -= chalk[j];
       }
       return 0;
    }
};

// static const int kd = [](){

// }