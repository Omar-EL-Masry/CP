  #include<bits/stdc++.h>
  using namespace std;
  struct Trie{
    struct Node{
      Node *child[2];
      Node(){
        memset(child, 0, sizeof child);
      }
    };
    Node *root;
    Trie(){
      root = new Node();
    }
    void add(int x){
      Node *node = root;
      for(int i = 31;i >= 0;i--){
        int bit = (x >> i) & 1;
        if(node -> child[bit] == NULL){
          node -> child[bit] = new Node();
        }
        node = node -> child[bit];
      }
    }
    int get(int x){
      Node *node = root;
      int res = 0;
      for(int i = 31;i >= 0;i--){
        int bit = (x >> i) & 1;
        if(node -> child[!bit] != NULL){
          res += (1ll << i);
          node = node -> child[!bit];
        }
        else if(node -> child[bit] != NULL){
          node = node -> child[bit];
        }
        else{
          assert(0);
        }
      }
      return res;
    }
  };
  int main(){
    return 0;
  }
