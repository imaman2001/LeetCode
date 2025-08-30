class Solution {
public:
    vector<vector<int>> generate(int n) {
        // vector<vector<int>> ans;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<=i; j++){
        //         if(j==0 || i==j){
        //             ans.push(1);
        //         } else {
        //             ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        //         }
        //     }
        // }
        // return ans;



        /*.......................*/
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int> row(i+1, 1);
            for(int j=1; j<i; j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};