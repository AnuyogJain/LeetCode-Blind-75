class Solution {
public:
    bool isCycle(vector<bool> &visited, vector<bool> &dfsvisited, int u, vector<int> adj[]) {
        visited[u] = true;
        dfsvisited[u] = true;
        
        for (auto it: adj[u]) {
            if (visited[it] == false) {
                if (isCycle(visited, dfsvisited, it, adj))
                    return true;
            }
            else {
                if (dfsvisited[it])
                    return true;
            }
        }
        
        dfsvisited[u] = false;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses + 1, false);
        vector<bool> dfsvisited(numCourses + 1, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                if (isCycle(visited, dfsvisited, i, adj))
                    return false;
            }
        }
        
        return true;
    }
};
