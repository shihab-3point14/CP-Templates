int prim(int V,vector<list<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(V, false);
    int res = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int wt = p.first; 
        int u = p.second; 

        if(visited[u] == true)continue;
        res += wt;  
        visited[u] = true;  
       
        for(auto v : adj[u]){
            if(visited[v.first] == false){
                pq.push({v.second, v.first});  
            }
        }
    }
    return res; 
}
// return parent array as a reference

int prim2(int V, vector<list<pair<int,int>>>& adj, vector<int>& parent) {
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<>> pq;
    vector<bool> visited(V, false);
    int res = 0;
    parent.assign(V, -1);
    pq.emplace(0, 0, -1);  // {weight, node, parent}

    while (!pq.empty()) {
        auto [wt, u, par] = pq.top(); 
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        parent[u] = par;
        res += wt;
        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                pq.emplace(w, v, u);
            }
        }
    }
    return res;
}

// return full graph edge
// {parent, child, weight}
// return total weight
pair<int, vector<tuple<int,int,int>>> prim3(int V, const vector<list<pair<int,int>>>& adj) {
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>> pq;
    vector<bool> vis(V,false);
    vector<tuple<int,int,int>> mst;
    int tot = 0;
    pq.emplace(0, 0, -1);
    while(!pq.empty()){
        auto [w,u,par] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=true; tot+=w;
        if(par!=-1) mst.emplace_back(par,u,w);
        for(auto [v,wt]: adj[u]){
            if(!vis[v]) pq.emplace(wt,v,u);
        }
    }
    return {tot,mst}; 

    // output format

    // pair<int, vector<tuple<int,int,int>>> prim3_ans = prim3(3, adj);
    // for(auto i: prim3_ans.second){
    //     cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    // }
    // cout << "Total weight: " << prim3_ans.first << endl;
}