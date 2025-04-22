// kahn's algorithm

vector<int> topotopological_sort(int n, vector<list<int>>& adj) {
    vector<int> indegree(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int u : adj[i]) {
            indegree[u]++;
        }
    }

    queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.front();
        pq.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    return ans;
}
