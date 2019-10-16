//%snippet.set('template')%
// template version 1.11
using namespace std;
#include <bits/stdc++.h>

// varibable settings {{{
#define int long long
#define infile "../test/sample-1.in"
// }}}
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

#if defined(PCM) || defined(LOCAL)
  #include "/home/koji0708/go/src/github.com/kjnh10/pcl/template/codes/lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

// #include "mint.cpp"
int mod = 1e9+7;
struct mint { //{{{
  int x;
  mint(int x=0):x((x%mod+mod)%mod){}

  // ?= operator
  mint& operator+=(const mint a) { (x += a.x) %= mod; return *this; }
  mint& operator-=(const mint a) { (x += mod-a.x) %= mod; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint&operator/=(const mint&rhs){return *this*=rhs.inv();}

  mint operator+(const mint a) const { mint res(*this); return res+=a; }
  mint operator-(const mint a) const { mint res(*this); return res-=a; }
  mint operator*(const mint a) const { mint res(*this); return res*=a; }
  mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}

  mint pow(int n)const{
    mint res(1),x(*this);
    if (n<0){
      n = -n;
      x =(*this).inv();
    }
    while(n){
      if(n&1)res*=x;
      x*=x;
      n>>=1;
    }
    return res;
  }
  mint inv()const{return pow(mod-2);}
  /*mint inv()const{
    int x,y;
    int g=extgcd(v,mod,x,y);
    assert(g==1);
    if(x<0)x+=mod;
    return mint(x);
    }*/
  friend ostream& operator<<(ostream&os,const mint&m){
    return os<<m.x;
  }
  bool operator<(const mint&r)const{return x<r.x;}
  bool operator==(const mint&r)const{return x==r.x;}
};
//}}}

// %snippet.set('generalized_baybe_step_giant_step')%
// %snippet.config({'alias':'gbsgs'})%
// %snippet.include('mint')%

int bsgs(int a, int b){ //{{{
  // find x s.t a^x = b in (mod)

  if (b>=mod) return -1;
  if (1%mod==b) return 0;

  int h = (int)sqrt(mod)+1; // h s.t x = p*h-r (0<=r<h and 0<=p<=h)

  unordered_map<int, vector<int>> rs; // rs[v]: vector of r s.t b*a^r==v
  mint bar = b;
  rep(r, 0, h){
    rs[bar.x].pb(r);
    bar *= a;
  }
  bool looped = false;
  each(el, rs) if (sz(el.second)>1) looped = true;

  mint ah = mint(a).pow(h);
  rep(p, 1, h+1){
    int aph = ah.pow(p).x;
    if (rs.find(aph)!=rs.end()){
      reverse(all(rs[aph]));
      each(r, rs[aph]){
        if ((p*h-r)>=0 && mint(a).pow(p*h-r)==b) return p*h-r;
      }
    }
    if (looped) return -1;
  }

  return -1;
} //}}}

// %snippet.end()%

signed main(){
  int a,b,p;cin>>a>>b>>p;
  mod = p;
  cout << bsgs(a, b) << endl;
  return 0;
}