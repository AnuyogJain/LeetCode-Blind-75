class Solution {
public:
    bool dfs(int i, int prev, vector<int> adj[], vector<bool> &visited) {
        if (visited[i] == true)
            return false;

        visited[i] = true;
        for (auto it: adj[i]) {
            if (it == prev)
                continue;
            else {
                if (dfs(it, i, adj, visited) == false)
                    return false;
            }
        }
        return true;
    }

    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (n == 0)
            return true;

        vector<int> adj[n];
        
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        //if no loop and all nodes are visited i.e., only single connected component
        //return true
        vector<bool> visited(n);
        bool loop = dfs(0, -1, adj, visited);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == false)
                return false;
        }

        return loop;
    }
};
