// dijkstra 
// ElogV
// V = number of nodes

vector<int> dijkstra(vector<list<pair<int,int>>>& adj,int n,int src){
    vector<int> dist(n,inf);
    set<pair<int,int>> st;
    st.insert({0,src});

    dist[src] = 0;

    while(!st.empty()){
        auto [curr_dis,u] = *st.begin();
        st.erase(st.begin());

        for(auto [v,w]:adj[u]){
            if(dist[v] > w){
                auto record = st.find({dist[v],v});
                if(record != st.end())st.erase({dist[v],v});
                dist[v] = w;
                st.insert({dist[v],v});
            }

        }
    }
    return dist;
}