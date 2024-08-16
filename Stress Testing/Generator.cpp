#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
#include "debug.h"
#define endl '\n'
#define int long long        
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()* ((uint64_t) new char | 1));
 
template<typename T>
T Rand(T low, T high) {
	return uniform_int_distribution<T>(low, high)(rng);
}
const long long mod = 998244353, Mxn = 1e5 + 5, INF = 1e18;
void gen()
{
        int x = Rand(1, 200);
        cout << x << endl;
}
signed main()
{
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        freopen("test.in", "w", stdout);
        // freopen("file.in","r",stdin);
        // freopen("file.out","w",stdout);
        int tc = 1;
        // cin >> tc;
        while (tc--)
        {
                gen();
        }
}

