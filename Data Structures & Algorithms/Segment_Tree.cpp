template<typename T>
struct Segment_Tree{
  int sz = 1, N;
  T Neutral;
  vector<T>tree;
  function<T(T, T)> merge;
  Segment_Tree(int _N, function< T (T, T) >_merge, T _Neutral = 0){
    merge = _merge;
    while(sz < _N)sz *= 2;
    N = sz * 2;
    tree.resize(N);
    Neutral = _Neutral;
  }
  #define left node * 2 + 1
  #define right node * 2 + 2
  void build(int idx, T val, int node, int l, int r){
    if(l == r)return void(tree[node] = val);
    int mid = l + r >> 1;
    if(idx <= mid)build(idx, val, left, l, mid);
    else build(idx, val, right, mid + 1, r);
    tree[node] = merge(tree[left], tree[right]);
  }
  void build(int idx, int val){
    build(idx, val, 0, 0, sz - 1);
  }

  T get(int lq, int rq, int node, int l, int r){
    if(l > rq || r < lq)return Neutral;
    if(l >= lq && r <= rq)return tree[node];
    int mid = l + r >> 1;
    return merge(get(lq, rq, left, l, mid), get(lq, rq, right, mid + 1, r));
  }
  T get(int lq, int rq){
    return get(lq, rq, 0, 0, sz - 1);
  }
  #undef left
  #undef right
};
