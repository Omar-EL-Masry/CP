#include<bits/stdc++.h>
using namespace std;
template<class T>struct Treap{
	struct Node{
		T val;
		int prior, cnt, sum;
		bool rev;
		Node *left, *right;
		Node(T v){
			val = v, cnt = 1, sum = val, prior = rand();
			rev = 0;
			left = right = nullptr;
		}
		friend int count(Node *node){
			return (node ? node -> cnt : 0);
		}
		void upd_cnt(){
			cnt = count(left) + count(right) + 1;
		}
		int Sum(Node *node){
			return (node ? node -> sum : 0);
		}
		void upd_sum(){
			sum = Sum(left) + Sum(right) + val;
		}
		void push(){
			if(rev){
				if(left)left -> rev ^= 1;
				if(right)right -> rev ^= 1;
				swap(left, right);
				rev = 0;
			}
		}
		void update(){
			upd_cnt();
			upd_sum();
			push();
		}
	};
	Node *root;
	Treap() : root(nullptr){};
	pair<Node*, Node*>split(Node *node, int p, int add = 0){
		pair<Node*, Node*>y = {nullptr, nullptr};
		if(!node)return y;
		node -> update();
		int key = add + 1 + count(node -> left);
		if(key <= p){
			y = split(node -> right, p, add + count(node -> left) + 1);
			node -> right = y.first;
			node -> update();
			y.first = node;
		}
		else{
			y = split(node -> left, p, add);
			node -> left = y.second;
			node -> update();
			y.second = node;
		}
		return y;
	}
	Node* merge(Node *&left, Node *&right){
		if(!left)return right;
		if(!right)return left;
		left -> update();
		right -> update();
		if(left -> prior > right -> prior){
			left -> right = merge(left -> right, right);
			left -> update();
			return left;
		}
		else{
			right -> left = merge(left, right -> left);
			right -> update();
			return right;
		}
	}
	void insert(T val){
		Node *New = new Node(val);
		root = merge(root, New);
	}
	void reverse(int L, int R){
		Node *left, *mid, *right;
		tie(left, right) = split(root, R);
		tie(left, mid) = split(left, L - 1);
		mid -> rev ^= 1;
		root = merge(left, mid);
		root = merge(root, right);
	}
	void print(Node *node){
		if(!node)return;
		print(node -> left);
		cout << node -> val << " ";
		print(node -> right);
	}
	int query(int L, int R){
		Node *left, *mid, *right;
		tie(left, right) = split(root, R);
		tie(left, mid) = split(left, L - 1);
		int res = (mid ? mid -> sum : 0);	
		root = merge(left, mid);
		root = merge(root, right);
		return res;
	}
};
int main(){
  return 0;
}
