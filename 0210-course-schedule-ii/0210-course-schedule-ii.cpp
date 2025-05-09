class Solution {
public:

    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& graph){
        vis[src] = true;
        recPath[src] = true;

        for(int i=0; i<graph.size(); i++){
            int u = graph[i][1];            // bcz these given opposite
            int v = graph[i][0];

            if(u == src){
                if(!vis[v]){ // if neighbour not visited --> mark visited as true
                    if(isCycle(v, vis, recPath, graph)){  // if in-future isCycle return's true
                        return true;
                    } 
                } else{         // else we visited
                        if(recPath[v]){  // if recPath mark already true
                            return true;
                        }
                    }
            } 
        }
        
        // mark recursion Path false during backtrack
        recPath[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& graph){
        vis[src] = true;

        for(int i=0; i<graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];

            if(u == src){
                if(!vis[v]){
                    topoSort(v, vis, s, graph);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        vector<int> ans;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, graph)){
                    return {};
                }
            }
        }

        // .. Topological Sort .. 
        vector<bool> vis2(V, false);
        stack<int> s;

        for(int i=0; i<V; i++){
            if(!vis2[i]){
                topoSort(i , vis2 , s , graph);
            }
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};