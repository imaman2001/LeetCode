class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int top = 0  , left  = 0;
        int bottom = n-1, right = n-1;
        int val = 1;

        while(top <= bottom && left <= right){
            //left to right
            for(int i=left; i<= right; i++){
                m[top][i] = val;
                val++;
            }
            top++;

            // top - bottom
            for(int i=top; i<=bottom; i++){
                m[i][right] = val;
                val++;
            }
            right--;

            //right to left
            if(top <= bottom){
                for(int i=right; i>=left; i--){
                    m[bottom][i] = val;
                    val++;
                }
                bottom--;
            }

            // bottom to top
            if(left <= right){
                for(int i=bottom; i>=top; i--){
                    m[i][left] = val;
                    val++;
                }
                left++;
            }
        }
        return m;
    }
};