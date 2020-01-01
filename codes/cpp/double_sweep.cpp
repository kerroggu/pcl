// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

void sputs(){}
template <class Head, class... Tail>
void sputs(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) == 0) { cout << endl; }
  else { cout << " "; }
  sputs(std::move(tail)...);
}

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

//%snippet.set('double_sweep')%

int double_sweep(const auto & g){/*{{{*/
  int n = sz(g);
  int x = 0;
  int max_d = 0;
  auto dfs = [&](const auto& dfs, auto& d, int u, int cost) -> void {
    each(v, g[u]){
      if (d[v]<INF) continue;
      d[v] = cost+1;
      if (d[v]>max_d){
        chmax(max_d, d[v]);
        x = v;
      }
      dfs(dfs, d, v, cost+1);
    }
  };

  vi d0(n, INF); d0[0] = 0;  // distance from 0
  dfs(dfs, d0, 0, 0);
  vi dx(n, INF); dx[x] = 0;  // distance from x
  int a = x;  // 保存

  max_d = 0;
  dfs(dfs, dx, x, 0);
  int b = x;

  return max_d; // d(a,b) == max_d;
}/*}}}*/

//%snippet.end()%

signed main() {
  int n;cin>>n;
  vvi g(n);
  rep(i, n-1){
    int a,b;cin>>a>>b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  int max_d = double_sweep(g);
  dump(max_d);

  vi dp(n+1);
  dp[0] = 1;
  dp[1] = 0;
  rep(i, 2, n+1){
    if (dp[i-1]==0 || dp[i-2]==0) dp[i] = 1;
  }
  cout << (dp[max_d]?"First":"Second") << endl;

  return 0;
}

