#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mxn = 200005, mod = 1000000007;
template<int Mod = mod> struct Mint{
  int val = 0;
  friend istream &operator>>(istream &is, Mint &x){
    is >> x.val;
    x.val = (x.val + Mod) % Mod;
    return is;
  }
  friend ostream &operator<<(ostream &os, Mint x){
    return os << x.val;
  }
  Mint(){};
  Mint(int _val){
    val = (_val + Mod) % Mod;
  }
  Mint operator+(Mint rhs){
    return Mint((this -> val + rhs.val) % Mod);
  }
  Mint operator%(int M){
    Mint ret;
    ret.val = (val + M) % M;
    return ret;
  }
  Mint& operator=(int x){
    val = (x + Mod) % Mod;
    return *this;
  }
  Mint& operator=(Mint x){
    val = (x.val + Mod) % Mod;
    return *this;
  }
  Mint operator-(Mint rhs){
    int ret = val - rhs.val + Mod;
    return Mint(ret % Mod);
  }
  Mint operator*(Mint rhs){
    return Mint((val * rhs.val) % Mod);
  }
  friend Mint power(Mint a, int b){
    if(b == 0)return Mint(1);
    Mint res = power(a, b / 2);
    res = res * res;
    if(b % 2){
      res = res * a;
    }
    return res;
  }
  friend Mint power(Mint a, Mint b){
    return power(a, b.val);
  }
  Mint inv(){
    return power(Mint(val), Mod - 2);
  }
  Mint operator/(Mint rhs){
    return *this * rhs.inv();
  }
  Mint &operator+=(Mint rhs){
    return *this = *this + rhs;
  }
  Mint &operator-=(Mint rhs){
    return *this = *this - rhs;
  }
  Mint &operator*=(Mint rhs){
    return *this = *this * rhs;
  }
  Mint &operator/=(Mint rhs){
    return *this = *this / rhs;
  }
  Mint &operator%=(int M){
    val = (val + M) % M;
    return *this;
  } 
  bool operator==(Mint rhs){
    return (val == rhs.val);
  }
  bool operator<(Mint rhs){
    return (val < rhs.val);
  }
  bool operator<=(Mint rhs){
    return (val <= rhs.val);
  }
  bool operator>(Mint rhs){
    return (val > rhs.val);
  }
  bool operator>=(Mint rhs){
    return (val >= rhs.val);
  }
};
int Mxm = 1000005;
vector<Mint<mod>>fact(Mxm), inv(Mxm);
void preproccess(){
  fact[0] = fact[1] = 1;
  for(int i = 2;i < Mxm;i++){
    fact[i] = fact[i - 1] * Mint(i);
  }
  inv[Mxm - 1] = fact[Mxm - 1].inv();
  for(int i = Mxm - 2;i >= 0;i--){
    inv[i] = inv[i + 1] * Mint(i + 1);
  }
}
Mint<mod> nCr(int a, int b){
  if(b > a)return 0;
  return fact[a] * inv[a - b] * inv[b]; 
}
signed main(){
  return 0;
}
