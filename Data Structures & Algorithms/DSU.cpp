#include<bits/stdc++.h>
using namespace std;
struct DSU{
	int sz;
	vector<int>par, size;
	DSU(int N){
		sz = N;
		par = size = vector<int>(sz, 1);
		iota(par.begin(), par.end(), 0);
	}
	int Find(int node){
		return (par[node] == node ? node : par[node] = Find(par[node]));
	}
	bool Union(int u, int v){
		u = Find(u), v = Find(v);
		if(u == v)return 1;
		if(size[u] < size[v])swap(u, v);
		size[u] += size[v];
		par[v] = u;
		return 0;
	}
};
int main(){
  return 0;
}
