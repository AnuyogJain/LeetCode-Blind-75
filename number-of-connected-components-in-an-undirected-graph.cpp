//547. Number of Provinces (Similar to Number of Connected Components in an Undirected Graph)


class Solution {
public:
    void dfs(vector<bool> &vis, int u, vector<int> adj[]) {
        vis[u] = true;
        
        for (auto it: adj[u]) {
            if(!vis[it]) {
			    dfs(vis, it, adj);
		    }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<bool> vis(n);
        
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                dfs(vis, i, adj);
                count++;
            }
        }
        
        return count;
    }
};
