class Solution {
private:
    bool bfs(int src,vector<int>vis,vector<vector<int>>adj,int n){
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(parent!=i){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) { 
         if (edges.size() != n - 1) return false;
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj,n)){
                    return false;
                }
            }
        }
        return true;
    
    }
};
