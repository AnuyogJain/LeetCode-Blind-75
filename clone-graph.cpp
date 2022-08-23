/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(unordered_map<Node*, Node*> &m, Node* node) {
        if (!node)
            return NULL;
        
        if (m.find(node) == m.end()) {
            Node* temp = new Node(node->val);
            m[node] = temp;
            for (int i = 0; i < node->neighbors.size(); i++) {
                temp->neighbors.push_back(dfs(m, node->neighbors[i]));
            }
        }
        
        return m[node];
    }
    
    Node* cloneGraph(Node* node) {
        //map old_nodes->new_nodes
        unordered_map<Node*, Node*> m;
        Node* ans = dfs(m, node);
        
        return ans;
    }
};
