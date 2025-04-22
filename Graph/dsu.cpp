// dsu with path compression and union by rank
// O(logn) for find_set and union_sets

// v = vertex

int v = 1e5+10;
vector<int> parent(v, -1);
vector<int> rank_(v,0);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}