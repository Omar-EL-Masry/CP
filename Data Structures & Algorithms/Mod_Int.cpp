#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mxn = 200005, mod = 1000000007;
template<int Mod = mod> struct Mod_int{
  int val = 0;
  friend istream &operator>>(istream &is, Mod_int &x){
    is >> x.val;
    x.val = (x.val + Mod) % Mod;
    return is;
  }
  friend ostream &operator<<(ostream &os, Mod_int x){
    return os << x.val;
  }
  Mod_int(){};
  Mod_int(int _val){
    val = (_val + Mod) % Mod;
  }
  Mod_int operator+(Mod_int rhs){
    return Mod_int((this -> val + rhs.val) % Mod);
  }
  Mod_int operator%(int M){
    Mod_int ret;
    ret.val = (val + M) % M;
    return ret;
  }
  Mod_int& operator=(int x){
    val = (x + Mod) % Mod;
    return *this;
  }
  Mod_int& operator=(Mod_int x){
    val = (x.val + Mod) % Mod;
    return *this;
  }
  Mod_int operator-(Mod_int rhs){
    int ret = val - rhs.val + Mod;
    return Mod_int(ret % Mod);
  }
  Mod_int operator*(Mod_int rhs){
    return Mod_int((val * rhs.val) % Mod);
  }
  friend Mod_int power(Mod_int a, int b){
    if(b == 0)return Mod_int(1);
    Mod_int res = power(a, b / 2);
    res = res * res;
    if(b % 2){
      res = res * a;
    }
    return res;
  }
  friend Mod_int power(Mod_int a, Mod_int b){
    return power(a, b.val);
  }
  Mod_int inv(){
    return power(Mod_int(val), Mod - 2);
  }
  Mod_int operator/(Mod_int rhs){
    return *this * rhs.inv();
  }
  Mod_int &operator+=(Mod_int rhs){
    return *this = *this + rhs;
  }
  Mod_int &operator-=(Mod_int rhs){
    return *this = *this - rhs;
  }
  Mod_int &operator*=(Mod_int rhs){
    return *this = *this * rhs;
  }
  Mod_int &operator/=(Mod_int rhs){
    return *this = *this / rhs;
  }
  Mod_int &operator%=(int M){
    val = (val + M) % M;
    return *this;
  } 
  bool operator==(Mod_int rhs){
    return (val == rhs.val);
  }
  bool operator<(Mod_int rhs){
    return (val < rhs.val);
  }
  bool operator<=(Mod_int rhs){
    return (val <= rhs.val);
  }
  bool operator>(Mod_int rhs){
    return (val > rhs.val);
  }
  bool operator>=(Mod_int rhs){
    return (val >= rhs.val);
  }
};
int Mxm = 1000005;
using Mint = Mod_int<mod>;
vector<Mint>fact(Mxm), inv(Mxm);
void preproccess(){
  fact[0] = fact[1] = 1;
  for(int i = 2;i < Mxm;i++){
    fact[i] = fact[i - 1] * Mod_int(i);
  }
  inv[Mxm - 1] = fact[Mxm - 1].inv();
  for(int i = Mxm - 2;i >= 0;i--){
    inv[i] = inv[i + 1] * Mod_int(i + 1);
  }
}
Mod_int<mod> nCr(int a, int b){
  if(b > a)return 0;
  return fact[a] * inv[a - b] * inv[b]; 
}
signed main(){
  return 0;
}
