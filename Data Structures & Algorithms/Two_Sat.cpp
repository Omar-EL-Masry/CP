#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>in, out, C;
vector<int>comp, opp;
int M, N, Mx;
void topo_sort(int u, vector<vector<int>> &adj, vector<int> &vis, vector<int> &order){
  if(vis[u])return;
  vis[u] = 1;
  for(auto v : adj[u])topo_sort(v, adj, vis, order);
  order.push_back(u);
}
void dfs(int u, int c, vector<vector<int>> &adj, vector<int> &vis){
  if(vis[u])return;
  vis[u] = 1;
  comp[u] = c;
  for(auto v : adj[u])dfs(v, c, adj, vis);
}
int get_idx(int x, int Nx){
  return 2 * x + Nx;
}
void add_edge(int u, int v){
  out[u].push_back(v);
  in[v].push_back(u);
}
void add_or_edge(int a, int b, int Na, int Nb){
  int from_a = get_idx(a, !Na), from_b = get_idx(b, !Nb);
  int to_a = from_a ^ 1, to_b = from_b ^ 1;
  add_edge(from_a, to_b);
  add_edge(from_b, to_a);
}
void condensate(){
  for(int i = 1;i < Mx;i++){
    if(comp[i] == comp[i ^ 1]){
      cout << "IMPOSSIBLE" << endl;
      exit(0);
    }
    opp[comp[i]] = comp[i ^ 1];
    for(auto u : out[i]){
      int A = comp[i], B = comp[u];
      if(A != B){
        C[A].push_back(B);
      }
    }
  }
}
vector<int>ans;
void Two_Sat(){
   vector<int>vis(Mx), order;
  for(int i = 1;i < Mx;i++){
    topo_sort(i, out, vis, order);
  }
  reverse(order.begin(), order.end());
  vis = vector<int>(Mx + 1);
  int c = 0;
  for(auto u : order){
    c += !vis[u];
    dfs(u, c, in, vis);
  }
  condensate();
  order.clear();
  vis = vector<int>(Mx + 1);
  for(int i = 1;i < Mx;i++){
    topo_sort(i, C, vis, order);
  }
  reverse(order.begin(), order.end());
  vector<int>res_c(Mx), done(Mx);
  for(auto u : order){
    if(!done[opp[u]]){
      res_c[u] = 0;
      done[u] = 1;
    }
    else{
      res_c[u] = 1;
    }
  }
  ans = vector<int>(N + 1);
  for(int i = 1;i <= N;i++){
    ans[i] = res_c[comp[i * 2]];
    assert(res_c[comp[i * 2]] ^ res_c[comp[i * 2 + 1]]);
  }
}
int main()
{
  return 0;
}
