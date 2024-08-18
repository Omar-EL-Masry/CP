#include<bits/stdc++.h>
using namespace std;
vector<int>fact(Mxn), inv(Mxn);
int mul(int a, int b){
  return a * b % mod;
}
int add(int a, int b){
  return (a + b) % mod;
}
int power(int a, int b){
  if(!b)return 1;
  int res = power(a, b >> 1);
  res = mul(res, res);
  if(b & 1)res = mul(res, a);
  return res;
}
int inverse(int a){
  return power(a, mod - 2);
}
void preproccess(){
  fact[0] = fact[1] = inv[0] = 1;
  for(int i = 2;i < Mxn;i++)fact[i] = mul(fact[i - 1], i);
  inv[Mxn - 1] = inverse(fact[Mxn - 1]);
  for(int i = Mxn - 2;i > 0;i--){
    inv[i] = mul(inv[i + 1], i + 1);
  }
}
int nCr(int n, int r){
  if(r > n)return 0;
  return mul(fact[n], mul(inv[n - r], inv[r]));
}

int main()
{
  return 0;
}
