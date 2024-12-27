#include<bits/stdc++.h>
using namespace std;
template<typename T> struct BIT{
  int sz;
  vector<T>tree;
  BIT(){};
  BIT(int N){
    sz = N + 1;
    tree.resize(sz);
  }
  int lsb(int x){
    return (x & -x);
  }
  void update(int idx, T x){
    for(;idx < sz;idx += lsb(idx))tree[idx] += x;
  }
  T get(int idx){
    T sum = 0;
    for(;idx;idx -= lsb(idx))sum += tree[idx];
    return sum;
  }
  T get(int l, int r){
    return get(r) - get(l - 1);
  }
};
int main(){
  return 0;
}
