class Solution {
    bool dfs(int src, int curr, vector<int> &color, vector<vector<int>>& graph){
        color[src] = curr;

        for(auto neighbour : graph[src]){
            //if neighbour has the same color , it's not bipartite (means lie in same set)
            if(color[neighbour] == curr){
                return false;
            }

            if(color[neighbour] == -1){
                // !col means not 1
                if(!dfs(neighbour, !curr, color, graph)){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);   // initilize all the values false

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if( !dfs(i, 0, color, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};