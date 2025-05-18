class DJS{
    vector<int> par;
    vector<int> rank;
public: 
    DJS(int n){
        rank.resize(n+1, 0);
        par.resize(n+1);

        for(int i=0; i<=n; i++){
            par[i] = i;
        }
    }

    // find parent of x
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void UnionRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        } else{
            par[parA] = parB;
        }
    }
};

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DJS djs(n);

        for(auto& e : edges){       // auto & id  for vector<vector<int>>
            int u = e[0];
            int v = e[1];

            if(djs.find(u) == djs.find(v)){
                return {u,v};
            } else{
                djs.UnionRank(u,v);
            }
        }
        return {};
    }
};