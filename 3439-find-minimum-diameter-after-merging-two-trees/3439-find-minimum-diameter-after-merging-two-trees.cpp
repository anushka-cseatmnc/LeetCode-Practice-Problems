class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> tree1 = findMinHeight(edges1.size() + 1, edges1);
        vector<int> tree2 = findMinHeight(edges2.size() + 1, edges2);
        return max({tree1[1], tree2[1], tree1[0] + tree2[0] + 1});
    }

    vector<int> findMinHeight(int n, vector<vector<int>>& edges) {
        if (n <= 2) return {n - 1, n - 1};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            degree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        int height = 0, lastLevelSize = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (int nbr : adj[curr]) {
                    degree[nbr]--;
                    if (degree[nbr] == 1) q.push(nbr);
                }
            }
            lastLevelSize = size;
            height++;
        }
        height--;
        int diam = 2 * height;
        if (lastLevelSize > 1) {
            height++;
            diam++;
        }
        return {height, diam};
    }
};