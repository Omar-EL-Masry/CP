  #include<bits/stdc++.h>
  using namespace std;
  #define int long long
  const long long mod = 1000000007, Mxn = 1e5 + 5, INF = 1e18;
  template<int Mod = mod, typename T = int> struct Mod_int{
    T val = 0;
    friend istream &operator>>(istream &is, Mod_int &x){
      is >> x.val;
      x.val = (x.val + Mod) % Mod;
      return is;
    }
    friend ostream &operator<<(ostream &os, Mod_int x){
      return os << x.val;
    }
    Mod_int(){};
    Mod_int(T _val){
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
    Mod_int& operator=(T x){
      val = (x + Mod) % Mod;
      return *this;
    }
    Mod_int& operator=(Mod_int x){
      val = (x.val + Mod) % Mod;
      return *this;
    }
    Mod_int operator-(Mod_int rhs){
      T ret = val - rhs.val + Mod;
      return Mod_int(ret % Mod);
    }
    Mod_int operator*(Mod_int rhs){
      return Mod_int((val * rhs.val) % Mod);
    }
    friend Mod_int power(Mod_int a, T b){
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
  template<typename T, int Base> struct Hasher{
    string s;
    int N;
    using Mint = Mod_int<mod, T>;
    vector<Mint>prefix, pw, suffix;  
    Hasher(string _s){
      N = _s.size();
      prefix.resize(N + 2);
      pw.resize(N + 2);
      suffix.resize(N + 2);
      s = _s;
      init();
    }
    void init(){
      pw[0] = 1;
      prefix[0] = s[0];
      for(int i = 1;i < N;i++){
        pw[i] = pw[i - 1] * Mint(Base);
        prefix[i] = (prefix[i - 1] * Base) + s[i];
      }
      suffix[N - 1] = s[N - 1];
      for(int i = N - 2;i >= 0;i--){
        suffix[i] = suffix[i + 1] * Base + s[i];
      }
    }
    Mint hash_prefix(int l, int r){
      Mint ret = prefix[r];
      if(l)ret -= (prefix[l - 1] * pw[r - l + 1]);
      return ret;
    }
    Mint hash_suffix(int l, int r){
      Mint ret = suffix[l];
      if(r < N)ret -= (suffix[r + 1] * pw[r - l + 1]);
      return ret;
    }
  };
  signed main(){
    return 0;
  }
