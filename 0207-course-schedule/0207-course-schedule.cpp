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

// find (DAG) means Directed Acyclic Graph and we assume directed also exist and now ind Acyclic
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses; // given prerequisites edges [v,u] v <-- u
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, prerequisites)){ // if cycle exist 
                    return false;
                }
            }
        }
        return true;
    }
};