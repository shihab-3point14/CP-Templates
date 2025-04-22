// kruskals algorithm
// O(ElogE)

bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int findParent(vector<int> &parent, int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[v] < rank[u]) {
        parent[v] = u;
        rank[u]++;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}
// here input is edges not adj
int calculateKruskalsMST(vector< vector<int> > &edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n);

    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sort(edges.begin(), edges.end(), compare);
    
    int minWeight = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v) {
            unionSet(u, v, parent, rank);
            minWeight += edges[i][2];
        }
    }

    return minWeight;
}