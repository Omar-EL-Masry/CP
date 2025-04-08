struct LCA{
  vector<vector<int>>anc, adj;
  vector<int>depth;
  int N, LgN;
  LCA(){};
  LCA(int _N, int _LgN, vector<vector<int>>_adj){
    N = _N, LgN = _LgN;
    adj = _adj;
    anc = vector<vector<int>>(N + 1, vector<int>(LgN + 1));
    depth = vector<int>(N + 1);
    dfs(1, 0, 0);
    precompute();
  }
  void dfs(int u, int par, int d){
    anc[u][0] = par;
    depth[u] = d;
    for(auto v : adj[u]){
      if(v == par)continue;
      dfs(v, u, d + 1);
    }
  }
  void precompute(){
    for(int i = 1;i < LgN;i++){
      for(int u = 1;u <= N;u++){
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
      }
    }
  }
  int get_kth(int u, int k){
    for(int i = 0;i < LgN;i++){
      if((k >> i) & 1)u = anc[u][i];
    }
    return u;
  }
  int Lca(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int dif = depth[u] - depth[v];
    u = get_kth(u, dif);
    if(u == v)return u;
    for(int i = LgN - 1;i >= 0;i--){
      if(anc[u][i] != anc[v][i]){
        u = anc[u][i], v = anc[v][i];
      }
    }
    return anc[u][0];
  }
  int dist(int u, int v){
    int lca = Lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
  }
};
