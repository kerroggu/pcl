---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/two_sat.hpp
    title: library/cpp/graph/two_sat.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/strongly_connected_components.hpp
    title: library/cpp/graph/strongly_connected_components.hpp
  - icon: ':question:'
    path: library/cpp/header.hpp
    title: library/cpp/header.hpp
  - icon: ':question:'
    path: library/cpp/graph/graph.hpp
    title: library/cpp/graph/graph.hpp
  - icon: ':question:'
    path: library/cpp/graph/edge.hpp
    title: library/cpp/graph/edge.hpp
  - icon: ':question:'
    path: library/cpp/graph/tree.lib/tree.hpp
    title: library/cpp/graph/tree.lib/tree.hpp
  - icon: ':question:'
    path: library/cpp/array/segtree/segment_tree.hpp
    title: library/cpp/array/segtree/segment_tree.hpp
  - icon: ':question:'
    path: library/cpp/graph/unionfind.hpp
    title: library/cpp/graph/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: library/cpp/graph/topological_sort.hpp
    title: library/cpp/graph/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/274
    links:
    - https://yukicoder.me/problems/no/274
  bundledCode: "#line 1 \"library/cpp/graph/tests/two_sat.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/274\"\n#line 2 \"library/cpp/header.hpp\"\
    \n\n//%snippet.set('header')%\n//%snippet.fold()%\n#ifndef HEADER_H\n#define HEADER_H\n\
    \n// template version 2.0\nusing namespace std;\n#include <bits/stdc++.h>\n\n\
    // varibable settings\nconst long long INF = 1e18;\ntemplate <class T> constexpr\
    \ T inf = numeric_limits<T>::max() / 2.1;\n\n#define _overload3(_1, _2, _3, name,\
    \ ...) name\n#define _rep(i, n) repi(i, 0, n)\n#define repi(i, a, b) for (ll i\
    \ = (ll)(a); i < (ll)(b); ++i)\n#define rep(...) _overload3(__VA_ARGS__, repi,\
    \ _rep, )(__VA_ARGS__)\n#define _rrep(i, n) rrepi(i, 0, n)\n#define rrepi(i, a,\
    \ b) for (ll i = (ll)((b)-1); i >= (ll)(a); --i)\n#define r_rep(...) _overload3(__VA_ARGS__,\
    \ rrepi, _rrep, )(__VA_ARGS__)\n#define each(i, a) for (auto &&i : a)\n#define\
    \ all(x) (x).begin(), (x).end()\n#define sz(x) ((int)(x).size())\n#define pb(a)\
    \ push_back(a)\n#define mp(a, b) make_pair(a, b)\n#define mt(...) make_tuple(__VA_ARGS__)\n\
    #define ub upper_bound\n#define lb lower_bound\n#define lpos(A, x) (lower_bound(all(A),\
    \ x) - A.begin())\n#define upos(A, x) (upper_bound(all(A), x) - A.begin())\ntemplate\
    \ <class T, class U> inline void chmax(T &a, const U &b) { if ((a) < (b)) (a)\
    \ = (b); }\ntemplate <class T, class U> inline void chmin(T &a, const U &b) {\
    \ if ((a) > (b)) (a) = (b); }\ntemplate <typename X, typename T> auto make_table(X\
    \ x, T a) { return vector<T>(x, a); }\ntemplate <typename X, typename Y, typename\
    \ Z, typename... Zs> auto make_table(X x, Y y, Z z, Zs... zs) { auto cont = make_table(y,\
    \ z, zs...); return vector<decltype(cont)>(x, cont); }\n\n#define cdiv(a, b) (((a)\
    \ + (b)-1) / (b))\n#define is_in(x, a, b) ((a) <= (x) && (x) < (b))\n#define uni(x)\
    \ sort(all(x)); x.erase(unique(all(x)), x.end())\n#define slice(l, r) substr(l,\
    \ r - l)\n\ntypedef long long ll;\ntypedef long double ld;\nusing vl = vector<ll>;\n\
    using vvl = vector<vl>;\nusing pll = pair<ll, ll>;\n\ntemplate <typename T>\n\
    using PQ = priority_queue<T, vector<T>, greater<T>>;\nvoid check_input() { assert(cin.eof()\
    \ == 0); int tmp; cin >> tmp; assert(cin.eof() == 1); }\n\n#if defined(PCM) ||\
    \ defined(LOCAL)\n#else\n#define dump(...) ;\n#define dump_1d(...) ;\n#define\
    \ dump_2d(...) ;\n#define cerrendl ;\n#endif\n\n#endif /* HEADER_H */\n//%snippet.end()%\n\
    #line 3 \"library/cpp/graph/edge.hpp\"\n\n//%snippet.set('edge')%\n//%snippet.fold()%\n\
    template<class Cost=ll>\nstruct Edge {\n    int from, to;\n    Cost cost;\n  \
    \  int idx;\n    Edge(){};\n    Edge(int from, int to, Cost cost, int idx)\n \
    \       : from(from), to(to), cost(cost), idx(idx) {}\n\n    friend ostream& operator<<(ostream&\
    \ os, const Edge& e) {\n        // os << \"(f:\" << e.from << \", t:\" << e.to\
    \ << \", c:\" << e.cost << \", i\" << e.idx << \")\";  // detailed\n        os\
    \ << \"(\" << e.from << \",\" << e.to << \")\";\n        return os;\n    }\n};\n\
    //%snippet.end()%\n#line 3 \"library/cpp/array/segtree/segment_tree.hpp\"\n//\
    \ http://tsutaj.hatenablog.com/entry/2017/03/29/204841\n\n//%snippet.set('segment_tree')%\n\
    //%snippet.config({'alias':'rmq'})%\n//%snippet.fold()%\n\ntemplate <typename\
    \ X> struct SegmentTree {  // {{{\n    private:\n        using F = function<X(X,\
    \ X)>;\n        using index = int;\n        int n;  // \u5143\u306E\u914D\u5217\
    \u306E\u30B5\u30A4\u30BA\n        int N;  // n\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    2\u51AA\n        vector<X> node;\n        F merge;\n        X identity;\n\n  \
    \  public:\n        SegmentTree() {}\n        SegmentTree(vector<X> a, F f, X\
    \ id) : merge(f), identity(id) {\n            n = a.size();\n            N = 1;\n\
    \            while (N < n) N *= 2;\n            node.resize(2 * N - 1, identity);\n\
    \            for (int i = 0; i < n; i++) node[i + N - 1] = a[i];\n           \
    \ for (int i = N - 2; i >= 0; i--)\n                node[i] = merge(node[2 * i\
    \ + 1], node[2 * i + 2]);\n        }\n        SegmentTree(int sz, F f, X id) :\
    \ SegmentTree(vector<X>(sz, id), f, id) {}\n\n        X& operator[](index i) {\
    \ return node[i + N - 1]; }\n\n        void set(index i, X val) {\n          \
    \  i += (N - 1);\n            node[i] = val;\n            while (i > 0) {\n  \
    \              i = (i - 1) / 2;\n                node[i] = merge(node[2 * i +\
    \ 1], node[2 * i + 2]);\n            }\n        }\n\n        void add(index i,\
    \ X val) {\n            i += (N - 1);\n            node[i] += val;\n         \
    \   while (i > 0) {\n                i = (i - 1) / 2;\n                node[i]\
    \ = merge(node[2 * i + 1], node[2 * i + 2]);\n            }\n        }\n\n   \
    \     // query for [a, b)\n        X query(index a, index b, int k = 0, index\
    \ l = 0, index r = -1) {\n            if (r < 0) r = N;\n            if (r <=\
    \ a || b <= l) return identity;\n            if (a <= l && r <= b) return node[k];\n\
    \n            X vl = query(a, b, 2 * k + 1, l, (l + r) / 2);\n            X vr\
    \ = query(a, b, 2 * k + 2, (l + r) / 2, r);\n            return merge(vl, vr);\n\
    \        }\n\n        index find_most_left(index l, const function<bool(X)>& is_ok){\n\
    \            // l\u304B\u3089\u53F3\u306B\u63A2\u3057\u3066\u3044\u3063\u3066\
    is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\
    \u8FD4\u3059\u3002\n            // assume query(l, *) has monotonity\n       \
    \     // return index i s.t is_ok(query(l, i)) does not holds, but is_ok(query(l,\
    \ i+1)) does.\n            // if such i does not exist, return n\n           \
    \ index res = _find_most_left(l, is_ok, 0, 0, N, identity).first;\n          \
    \  assert(l <= res);\n            return res;\n        }\n        pair<index,\
    \ X> _find_most_left(index a, const function<bool(X)>& is_ok, int k, index l,\
    \ index r, X left_value){\n            // params:\n                // left_value\
    \ = (a < l ? query(a, l) : ex)\n            // return (index i, X v)\n       \
    \         // i is the index in [a, n)^[l, r) s.t query(a, i+1) is ok but query(a,\
    \ i) isn't ok. if such i does not exist, i = n\n                // v is the value\
    \ s.t query(a, r)\n\n            if (r <= a) return {n, identity};  // \u533A\u9593\
    \u304C\u5168\u304F\u88AB\u3063\u3066\u3044\u306A\u3044\n            else if (a\
    \ <= l && !is_ok(merge(left_value, node[k]))) return {n, merge(left_value, node[k])};\n\
    \            else if (k >= N-1) return {k - (N-1), merge(left_value, node[k])};\n\
    \            else{\n                auto [vl, xl] = _find_most_left(a, is_ok,\
    \ 2 * k + 1, l, (l + r) / 2, left_value);\n                if (vl != n) return\
    \ {vl, xl};\n                auto [vr, xr] = _find_most_left(a, is_ok, 2 * k +\
    \ 2, (l + r) / 2, r, xl);\n                return {vr, xr};\n            }\n \
    \       }\n\n        index find_most_right(index r, const function<bool(X)>& is_ok){\n\
    \            // r\u304B\u3089\u5DE6\u306B\u63A2\u3057\u3066\u3044\u3063\u3066\
    is_ok\u304C\u521D\u3081\u3066\u6210\u308A\u7ACB\u3064\u3088\u3046\u306Aindex\u3092\
    \u8FD4\u3059\u3002\n            // assume query(*, r) has monotonity\n       \
    \     // return index i s.t is_ok(query(i+1, r+1)) does not holds, but is_ok(query(i,\
    \ r+1)) does.\n            // if such i does not exist, return -1\n          \
    \  index res = _find_most_right(r+1, is_ok, 0, 0, N, identity).first;\n      \
    \      assert(res <= r);\n            return res;\n        }\n        pair<index,\
    \ X> _find_most_right(index b, const function<bool(X)>& is_ok, int k, index l,\
    \ index r, X right_value){\n            if (b <= l) return {-1, identity};  //\
    \ \u533A\u9593\u304C\u5168\u304F\u88AB\u3063\u3066\u3044\u306A\u3044\n       \
    \     else if (r <= b && !is_ok(merge(node[k], right_value))) return {-1, merge(node[k],\
    \ right_value)};\n            else if (k >= N-1) return {k - (N-1), merge(node[k],\
    \ right_value)};\n            else{\n                auto [vr, xr] = _find_most_right(b,\
    \ is_ok, 2 * k + 2, (l + r) / 2, r, right_value);\n                if (vr != -1)\
    \ return {vr, xr};\n                auto [vl, xl] = _find_most_right(b, is_ok,\
    \ 2 * k + 1, l, (l + r) / 2, xr);\n                return {vl, xl};\n        \
    \    }\n        }\n\n        #if defined(PCM) || defined(LOCAL)\n        friend\
    \ ostream& operator<<(ostream& os, SegmentTree<X>& sg) {  //\n            os <<\
    \ \"[\";\n            for (int i = 0; i < sg.n; i++) {\n                os <<\
    \ sg[i] << (i == sg.n - 1 ? \"]\\n\" : \", \");\n            }\n            return\
    \ os;\n        }\n        #endif\n};/*}}}*/\n// sample of initialize SegmentTree:\n\
    // -----------------------------------------------\n// auto mymin=[](auto a, auto\
    \ b){return min(a,b);};\n// SegmentTree<ll> seg(a, mymin, 1e18);\n\n// auto mymax=[](auto\
    \ a, auto b){return max(a,b);};\n// SegmentTree<ll> seg(a, mymax, -1e18);\n\n\
    // auto add=[](auto a, auto b){return a+b;};\n// SegmentTree<ll> seg(a, add, 0);\n\
    \n// pair<int, int> get_nearest_index_of_smaller_element(int i){\n//     auto\
    \ left = seg.find_most_right(i, [&](auto x){return x < a[i];});\n//     auto right\
    \ = seg.find_most_left(i, [&](auto x){return x < a[i];});\n//     return {left,\
    \ right};\n// }\n// -----------------------------------------------\n\n//%snippet.end()%\n\
    #line 5 \"library/cpp/graph/tree.lib/tree.hpp\"\n// (ref) https://www.slideshare.net/Proktmr/ss-138534092\n\
    // (ref:HL decomposition) https://qiita.com/Pro_ktmr/items/4e1e051ea0561772afa3\n\
    \n//%snippet.set('tree')%\n//%snippet.include('segment_tree')%\n//%snippet.include('edge')%\n\
    //%snippet.fold()%\ntemplate<class Cost=ll>\nstruct tree { \n    int n;\n    int\
    \ root;\n    vector<int> par;   // par[i]: dfs\u6728\u306B\u304A\u3051\u308B\u89AA\
    \n    vector<Cost> cost;  // par[i]: dfs\u6728\u306B\u304A\u3051\u308B\u89AA\u3078\
    \u306E\u8FBA\u306E\u30B3\u30B9\u30C8\n    vector<int> dfstrv;  // dfstrv[i]: dfs\u6728\
    \u3067i\u756A\u76EE\u306B\u8A2A\u308C\u308B\u30CE\u30FC\u30C9\u3002dp\u306F\u3053\
    \u308C\u3092\u9006\u9806\u306B\u56DE\u3059\n    vector<int> ord;    // ord[u]:\
    \ u\u306Edfs\u6728\u306B\u304A\u3051\u308B\u8A2A\u554F\u9806\n    vector<int>\
    \ end;    // end[u]: u\u306Edfs\u7D42\u4E86\u6642\u306E\u30AB\u30A6\u30F3\u30BF\
    \u30FC\n    vector<int> psize;  // psize[u]: u\u306Epartial tree size\n    //\
    \ u\u306E\u90E8\u5206\u6728\u306F[ord[u], end[u])\n    // ord\u3068dfstrv\u306F\
    \u9006\u5909\u63DB\n    vector<int> depth;   // depth[i]: dfs\u6728\u3067\u306E\
    i\u306E\u6DF1\u3055\n    vector<Cost> ldepth;  //  ldepth[i]: dfs\u6728\u3067\u306E\
    root\u304B\u3089\u306E\u8DDD\u96E2\n    vector<vector<Edge<Cost>>> adj_list; \
    \      // \u8FBA(\u96A3\u63A5\u30EA\u30B9\u30C8)\n    auto operator[](int pos)\
    \ const { return adj_list[pos]; }\n    vector<vector<int>> children;\n    vector<int>\
    \ euler_tour;\n    vector<int> et_fpos;    // euler_tour first occurence position\n\
    \    SegmentTree<int> _seg;  // seg(map(ord, euler_tour), mymin, 1e18)\n    vector<int>\
    \ head_of_comp;\n    int _counter = 0;\n\n    tree(){};/*{{{*/\n    tree(int n)\n\
    \        : n(n),\n          par(n),\n          cost(n),\n          ord(n),\n \
    \         end(n),\n          psize(n),\n          depth(n),\n          ldepth(n),\n\
    \          adj_list(n),\n          children(n),\n          et_fpos(n),\n     \
    \     head_of_comp(n){};/*}}}*/\n    void add_edge(int u, int v, Cost cost, int\
    \ idx=-1) { /*{{{*/\n        adj_list[u].emplace_back(u, v, cost, idx);\n    \
    \    adj_list[v].emplace_back(v, u, cost, idx);\n    }                       \
    \      /*}}}*/\n    void add_edge(int u, int v) { /*{{{*/\n        adj_list[u].emplace_back(u,\
    \ v, 1, -1);\n        adj_list[v].emplace_back(v, u, 1, -1);\n    }          \
    \            /*}}}*/\n    void build(int _root) { /*{{{*/\n        root = _root;\n\
    \        _counter = 0;\n        par[root] = -1;\n        // cost[root] = -1;\n\
    \        _dfs_psize(root, -1);\n        _dfs_tree(root, -1, root);\n        _dfs_et(root);\n\
    \        vector<int> ini(2 * n - 1);\n        rep(i, 2 * n - 1) ini[i] = ord[euler_tour[i]];\n\
    \        _seg = SegmentTree<int>(\n            ini, [](auto a, auto b) { return\
    \ min(a, b); }, numeric_limits<int>().max());\n    }                         \
    \       /*}}}*/\n    int _dfs_psize(int u, int pre) { /*{{{*/\n        psize[u]\
    \ = 1;\n        each(edge, adj_list[u]) {\n            if (edge.to == pre) continue;\n\
    \            psize[u] += _dfs_psize(edge.to, u);\n        }\n        return psize[u];\n\
    \    }                                               /*}}}*/\n    void _dfs_tree(int\
    \ u, int pre, int head_node) { /*{{{*/\n        dfstrv.pb(u);\n        ord[u]\
    \ = _counter;\n        if (pre != -1) {\n            depth[u] = depth[pre] + 1;\n\
    \            ldepth[u] = ldepth[pre] + cost[u];\n        }\n\n        _counter++;\n\
    \        {\n            // set most heavy child to top\n            int max_psize\
    \ = 0;\n            int most_heavy_i = -1;\n            rep(i, sz(adj_list[u]))\
    \ {\n                if (adj_list[u][i].to == pre) continue;\n               \
    \ if (psize[adj_list[u][i].to] > max_psize) {\n                    most_heavy_i\
    \ = i;\n                    max_psize = psize[adj_list[u][i].to];\n          \
    \      }\n            }\n            if (most_heavy_i != -1) swap(adj_list[u][most_heavy_i],\
    \ adj_list[u][0]);\n        }\n\n        head_of_comp[u] = head_node;\n      \
    \  rep(i, sz(adj_list[u])) {\n            int v = adj_list[u][i].to;\n       \
    \     if (v == pre) continue;\n\n            children[u].pb(v);\n            par[v]\
    \ = u;\n            cost[v] = adj_list[u][i].cost;\n\n            if (i == 0)\n\
    \                _dfs_tree(v, u, head_node);  // continue components\n       \
    \     else\n                _dfs_tree(v, u, v);  // new\n        }\n        end[u]\
    \ = _counter;\n    }                     /*}}}*/\n    void _dfs_et(int u) { /*{{{*/\n\
    \        et_fpos[u] = euler_tour.size();\n        euler_tour.pb(u);\n        each(v,\
    \ children[u]) {\n            _dfs_et(v);\n            euler_tour.pb(u);\n   \
    \     }\n    }                       /*}}}*/\n    int lca(int u, int v) { /*{{{*/\n\
    \        if (u == v) return u;\n        if (et_fpos[u] > et_fpos[v]) swap(u, v);\n\
    \        return dfstrv[_seg.query(et_fpos[u], et_fpos[v])];\n    }           \
    \             /*}}}*/\n    int dist(int u, int v) { /*{{{*/\n        int p = lca(u,\
    \ v);\n        return depth[u] + depth[v] - 2 * depth[p];\n    }             \
    \             /*}}}*/\n    Cost ldist(int u, int v) {  // length dist{{{\n   \
    \     int p = lca(u, v);\n        return ldepth[u] + ldepth[v] - 2 * ldepth[p];\n\
    \    }                           /*}}}*/\n    pair<int, int> diameter() { /*{{{*/\n\
    \        int u, v;\n        Cost max_len = *max_element(all(ldepth));\n      \
    \  rep(i, n) {\n            if (ldepth[i] == max_len) {\n                u = i;\n\
    \                break;\n            }\n        }\n        Cost md = -1;\n   \
    \     rep(i, n) {\n            Cost d = ldist(u, i);\n            if (d > md)\
    \ {\n                v = i;\n                md = d;\n            }\n        }\n\
    \        return mp(u, v);\n    }                                             \
    \   /*}}}*/\n    vector<pair<int, int>> hld_path(int u, int v, bool for_edge=true)\
    \ {  //{{{\n        // \u9589\u533A\u9593\u3092vector\u3067\u8FD4\u3059\u3002\
    for_edge=true\u3067lca\u306F\u9664\u3044\u3066\u8FD4\u3059\u3053\u3068\u306B\u6CE8\
    \u610F\u3002\n        vector<pair<int, int>> res;\n        while (head_of_comp[u]\
    \ != head_of_comp[v]) {\n            if (depth[head_of_comp[u]] < depth[head_of_comp[v]])\
    \ {\n                res.push_back({ord[head_of_comp[v]], ord[v]});\n        \
    \        v = par[head_of_comp[v]];\n            } else {\n                res.push_back({ord[head_of_comp[u]],\
    \ ord[u]});\n                u = par[head_of_comp[u]];\n            }\n      \
    \  }\n        res.push_back({min(ord[u], ord[v]) + (for_edge?1:0), max(ord[u],\
    \ ord[v])});\n        return res;\n    }                              //}}}\n\
    #if defined(PCM) || defined(LOCAL) /*{{{*/\n    friend ostream& operator<<(ostream&\
    \ os, const tree& tr) {\n        os << endl;\n        os << \"par:         \"\
    \ << tr.par << endl;\n        os << \"cost:        \" << tr.cost << endl;\n  \
    \      os << \"dfstrv:      \" << tr.dfstrv << endl;\n        os << \"ord:   \
    \      \" << tr.ord << endl;\n        os << \"end:         \" << tr.end << endl;\n\
    \        os << \"depth:       \" << tr.depth << endl;\n        os << \"children:\
    \    \" << tr.children << endl;\n        os << \"euler_tour:  \" << tr.euler_tour\
    \ << endl;\n        os << \"et_fpos:     \" << tr.et_fpos << endl;\n        os\
    \ << \"head_of_comp:\" << tr.head_of_comp << endl;\n        return os;\n    }\n\
    #endif /*}}}*/\n}; \n//%snippet.end()%\n#line 3 \"library/cpp/graph/unionfind.hpp\"\
    \n\n//%snippet.set('UnionFind')%\n//%snippet.fold()%\n\nstruct UnionFind {\n \
    \   vector<int> par;   // par[x]: parent of x. if root, -size.\n    int gcount;\
    \         // count of groups\n\n    UnionFind() {}\n    UnionFind(int _n) : par(_n,\
    \ -1), gcount(_n) {}\n    bool merge(int x, int y) { \n        x = root(x);\n\
    \        y = root(y);\n        if (x != y) {\n            if (par[y] < par[x])\
    \ swap(x, y);\n            par[x] += par[y];\n            par[y] = x;\n      \
    \      gcount--;\n        }\n        return x != y;\n    } \n    int root(int\
    \ x) {\n        if (is_root(x)){\n            return x;\n        }\n        else{\n\
    \            return par[x] = root(par[x]);  // \u7D4C\u8DEF\u5727\u7E2E\n    \
    \        // return root(par[x]);         // \u7D4C\u8DEF\u5727\u7E2E\u306A\u3057\
    \n        }\n    }\n    bool is_root(int x) { return par[x] < 0; }\n    bool same(int\
    \ x, int y) { return root(x) == root(y); }\n    int size(int x) { return -par[root(x)];\
    \ }\n\n#if defined(PCM) || defined(LOCAL)  // {{{\n    friend ostream& operator<<(ostream&\
    \ os, UnionFind& uf) {\n        map<int, vector<int>> group;\n        rep(i, sz(uf.par))\
    \ { group[uf.root(i)].pb(i); }\n        os << endl;\n        each(g, group) {\
    \ os << g << endl; }\n        return os;\n    }\n#endif  // }}}\n};\n\n//%snippet.end()%\n\
    #line 6 \"library/cpp/graph/graph.hpp\"\n\n//%snippet.set('Graph')%\n//%snippet.include('UnionFind')%\n\
    //%snippet.include('tree')%\n//%snippet.fold()%\n\ntemplate<class Cost=ll>\nstruct\
    \ Graph {\n    using Pos = int;  // int\u4EE5\u5916\u306B\u306F\u5BFE\u5FDC\u3057\
    \u306A\u3044\u3002\n\n    int n;  // \u9802\u70B9\u6570\n    vector<vector<Edge<Cost>>>\
    \ adj_list;\n    auto operator[](Pos pos) const { return adj_list[pos]; }\n  \
    \  vector<Edge<Cost>> edges;\n    tree<Cost> tr;\n    Pos root;\n    vector<int>\
    \ _used_in_dfs;\n    vector<int> lowlink;\n    Cost zerocost;\n    Cost infcost;\n\
    \n    Graph() {}\n    Graph(int _n) : n(_n), adj_list(_n), tr(n), _used_in_dfs(n),\
    \ zerocost(0LL), infcost(INF) { }\n    Graph(int _n, Cost zc, Cost ic) : n(_n),\
    \ adj_list(_n), tr(n), _used_in_dfs(n), zerocost(zc), infcost(ic) { }\n\n    void\
    \ add_edge(Pos from, Pos to, Cost cost, int idx=-1) {/*{{{*/\n        adj_list[from].emplace_back(from,\
    \ to, cost, idx);\n        edges.emplace_back(from, to, cost, idx);\n    }\n \
    \   void add_edge(Pos from, Pos to) {  // for ll\n        adj_list[from].emplace_back(from,\
    \ to, 1, -1);\n        edges.emplace_back(from, to, 1, -1);\n    }/*}}}*/\n\n\
    \    void build_tree(Pos _root) {/*{{{*/\n        root = _root;\n        _dfs_tree(root);\n\
    \        tr.build(root);\n        _make_lowlink();\n    }/*}}}*/\n\n    vector<int>\
    \ make_bipartite() {/*{{{*/\n        UnionFind buf(2 * n);\n        rep(u, n)\
    \ {\n            each(e, adj_list[u]) {\n                buf.merge(u, e.to + n);\n\
    \                buf.merge(e.to, u + n);\n            }\n        }\n\n       \
    \ vector<int> res(n, -1);\n        rep(u, n) {\n            if (buf.same(u, u\
    \ + n)) return res;\n        }\n        rep(u, n) {\n            if (buf.same(0,\
    \ u)) res[u] = 0;\n            else res[u] = 1;\n        }\n        return res;\n\
    \    }/*}}}*/\n\n    void _dfs_tree(Pos u) {/*{{{*/\n        _used_in_dfs[u] =\
    \ 1;\n        each(e, adj_list[u]) {\n            if (_used_in_dfs[e.to]) continue;\n\
    \            tr.add_edge(u, e.to, e.cost);\n            _dfs_tree(e.to);\n   \
    \     }\n    }/*}}}*/\n\n    void _make_lowlink() {/*{{{*/\n        lowlink =\
    \ vector<Pos>(n, numeric_limits<Pos>().max());\n        r_rep(i, n) {\n      \
    \      Pos u = tr.dfstrv[i];\n            chmin(lowlink[u], tr.ord[u]);\n\n  \
    \          each(e, adj_list[u]) {\n                if (e.to == tr.par[u])\n  \
    \                  continue;\n                else if (tr.ord[e.to] < tr.ord[u])\
    \ {\n                    chmin(lowlink[u], tr.ord[e.to]);\n                } else\
    \ {\n                    chmin(lowlink[u], lowlink[e.to]);\n                }\n\
    \            }\n        }\n    }/*}}}*/\n\n    vector<Pos> get_articulation_points()\
    \ {/*{{{*/\n        if (sz(lowlink) == 0) throw(\"make_lowlik() beforehand\");\n\
    \n        vector<Pos> res;\n        if (sz(tr.children[root]) > 1) {\n       \
    \     res.push_back(root);\n        }\n        rep(u, 0, n) {\n            if\
    \ (u == root) continue;\n            bool is_kan = false;\n            each(v,\
    \ tr.children[u]) {\n                if (tr.ord[u] <= lowlink[v]) {\n        \
    \            is_kan = true;\n                }\n            }\n            if\
    \ (is_kan) res.push_back(u);\n        }\n        return res;\n    }/*}}}*/\n\n\
    \    vector<Edge<Cost>> get_bridges() {/*{{{*/\n        if (sz(lowlink) == 0)\
    \ throw(\"make_lowlik() beforehand\");\n        vector<Edge<Cost>> res;\n    \
    \    each(edge, edges){\n            if (tr.ord[edge.from] < lowlink[edge.to])\
    \ res.push_back(edge);\n        }\n        return res;\n    }/*}}}*/\n\n    vector<Edge<Cost>>\
    \ kruskal_tree() {/*{{{*/\n        // \u4F7F\u7528\u3055\u308C\u308B\u8FBA\u306E\
    vector\u3092\u8FD4\u3059\n        vector<Edge<Cost>> res(n - 1);\n        sort(all(edges),\
    \ [&](auto l, auto r) { return l.cost < r.cost; });\n        UnionFind uf(n);\n\
    \n        Cost total_cost = zerocost;\n        int idx = 0;\n        each(e, edges)\
    \ {\n            if (uf.same(e.from, e.to)) continue;\n            uf.merge(e.from,\
    \ e.to);\n            total_cost = total_cost + e.cost;\n            res[idx]\
    \ = e;\n            idx++;\n        }\n        assert(idx == n - 1);\n\n     \
    \   return res;\n    }/*}}}*/\n\n    vector<Cost> dijkstra(vector<Pos> starts)\
    \ {  // \u591A\u70B9\u30B9\u30BF\u30FC\u30C8{{{\n        vector<Cost> dist(n,\
    \ infcost);           // \u6700\u77ED\u8DDD\u96E2\n        PQ<pair<Cost, Pos>>\
    \ pq;\n        each(start, starts) {\n            dist[start] = zerocost;\n  \
    \          pq.push(make_pair(zerocost, start));\n        }\n        while (!pq.empty())\
    \ {\n            auto cp = pq.top();\n            pq.pop();\n            auto\
    \ [cost, u] = cp;\n            for (const auto& edge : adj_list[u]) {\n      \
    \          Cost new_cost = cost + edge.cost;  // TODO: \u554F\u984C\u306B\u3088\
    \u3063\u3066\u306F\u3053\u3053\u304C\u5909\u66F4\u306E\u5FC5\u8981\u3042\u308A\
    \n                if (new_cost < dist[edge.to]) {\n                    dist[edge.to]\
    \ = new_cost;\n                    pq.push(make_pair(new_cost, edge.to));\n  \
    \              }\n            }\n        }\n        return dist;\n    };/*}}}*/\n\
    \n    vector<Cost> dijkstra(Pos start) {  // 1\u70B9\u30B9\u30BF\u30FC\u30C8{{{\n\
    \        vector<Pos> starts = {start};\n        return dijkstra(starts);\n   \
    \ };/*}}}*/\n};\n\n//%snippet.end()%\n#line 3 \"library/cpp/graph/strongly_connected_components.hpp\"\
    \n\n//%snippet.set('scc')%\n//%snippet.config({'alias':'StronglyConnectedComponents'})%\n\
    //%snippet.include('Graph')%\n//%snippet.fold()%\n\ntemplate<class T = ll>\nstruct\
    \ StronglyConnectedComponents {\n    const Graph<T> &g;  //{{{\n    vector<int>\
    \ comp;  // comp[i]: i\u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u304C\
    \u4F55\u756A\u76EE\u306E\u6210\u5206\u304B\n    Graph<> dag;  // \u7E2E\u7D04\u3055\
    \u308C\u305FDAG graph. size\u3092\u3068\u308C\u3070\u5F37\u9023\u7D50\u6210\u5206\
    \u306E\u500B\u6570\u304C\u5206\u304B\u308B\u3002\n    Graph<> _rg;  // reversed\
    \ graph\n    vector<int> _order;  // order[i]: \u5E30\u308A\u304C\u3051\u9806\n\
    \    vector<int> _used;\n\n    StronglyConnectedComponents(Graph<T> &_g)\n   \
    \     : g(_g), comp(_g.n, -1), _rg(_g.n), _used(_g.n) {\n        for (int i =\
    \ 0; i < g.n; i++) {\n            for (auto e : g[i]) {\n                _rg.add_edge(e.to,\
    \ e.from);\n            }\n        }\n        _build();\n    }\n\n    int operator[](int\
    \ k) { return comp[k]; }\n\n    void _build() {\n        for (int i = 0; i < g.n;\
    \ i++) _dfs(i);\n        reverse(begin(_order), end(_order));\n        int cnt\
    \ = 0;\n        for (int u : _order)\n            if (comp[u] == -1) _rdfs(u,\
    \ cnt), cnt++;\n\n        dag = Graph(cnt);\n        for (int u = 0; u < g.n;\
    \ u++) {\n            for (auto &e : g[u]) {\n                if (comp[u] == comp[e.to])\
    \ continue;\n                dag.add_edge(comp[u], comp[e.to]);\n            }\n\
    \        }\n    }\n\n    void _dfs(int idx) {\n        if (_used[idx]) return;\n\
    \        _used[idx] = true;\n        for (auto &e : g[idx]) _dfs(e.to);\n    \
    \    _order.push_back(idx);\n    }\n\n    void _rdfs(int idx, int cnt) {\n   \
    \     if (comp[idx] != -1) return;\n        comp[idx] = cnt;\n        for (auto\
    \ e : _rg[idx]) _rdfs(e.to, cnt);\n    }  //}}}\n};\n// how to use\n// StronglyConnectedComponents\
    \ scc(g); // g: Graph\n// dump(scc.comp, scc.dag.adj_list);\n\n//%snippet.end()%\n\
    \n\n#line 3 \"library/cpp/graph/topological_sort.hpp\"\n\n//%snippet.set('topological_sort')%\n\
    //%snippet.include('Graph')%\n//%snippet.config({'alias':'tps'})%\n//%snippet.fold()%\n\
    \nusing Pos = int;\ntuple<bool, vector<Pos>, int> topological_sort(const Graph<>&\
    \ g) {\n    vector<Pos> res;  // sort\u5F8C\u306E\u7D50\u679C\u3092\u683C\u7D0D\
    \n    vector<int> h(g.n);  // \u9802\u70B9\u3054\u3068\u306E\u5165\u6B21\u6570\
    \n    stack<Pos> st;    // \u5165\u6B21\u6570\u304C0\u306B\u306A\u3063\u3066\u3044\
    \u308B\u9802\u70B9\u306E\u96C6\u5408\n    int max_len = 0;   // \u6700\u9577\u7D4C\
    \u8DEF\u306E\u9577\u3055\n\n    // \u5165\u6B21\u6570\u3092\u8A08\u7B97\u3059\u308B\
    \u3002\n    rep(u, g.n) {\n        for (const auto& edge : g[u]) {\n         \
    \   h[edge.to]++;\n        }\n    }\n\n    // \u6700\u521D\u306B\u5165\u6B21\u6570\
    0\u306B\u306A\u3063\u3066\u3044\u308B\u9802\u70B9\u3092\u96C6\u3081\u308B\u3002\
    \n    rep(u, g.n) {\n        if (h[u] == 0) {\n            st.push(u);\n     \
    \       res.push_back(u);\n        }\n    }\n\n    // \u5165\u6B21\u65700\u306E\
    \u9802\u70B9\u3092res\u306B\u8FFD\u52A0\u3057\u305D\u3053\u304B\u3089\u51FA\u3066\
    \u884C\u304F\u8FBA\u306F\u524A\u9664\u3057\u3066\u3044\u304F\u3002O(g.n+E)\n \
    \   while (!st.empty()) {\n        stack<Pos> nex_st;\n        while (!st.empty())\
    \ {\n            Pos u = st.top(); st.pop();\n            for (const auto& edge\
    \ : g[u]) {\n                h[edge.to]--;\n                if (h[edge.to] ==\
    \ 0) {\n                    res.push_back(edge.to);\n                    nex_st.push(edge.to);\n\
    \                }\n            }\n        }\n        max_len++;\n        st =\
    \ nex_st;\n    }\n    \n    bool is_valid = (sz(res)==g.n ? true : false);\n \
    \   return {is_valid, res, max_len};  // res.size()<g.n\u306A\u3089\u9589\u8DEF\
    \u304C\u3042\u308ADAG\u3067\u306F\u306A\u3044\u3002\u9589\u8DEF\u5185\u306E\u9802\
    \u70B9\u306Fst\u306B\u5165\u308A\u5F97\u306A\u3044\u306E\u3067\u3002\n}\n//%snippet.end()%\n\
    \n#line 3 \"library/cpp/graph/two_sat.hpp\"\n\n//%snippet.set('two_sat')%\n//%snippet.include('scc')%\n\
    //%snippet.include('topological_sort')%\n//%snippet.fold()%\n\nstruct two_sat{\n\
    \    using Pos = int;\n    using Size = int;\n    Size orig_n;\n    Graph<bool>\
    \ g;\n    vector<int> assigned;\n\n    two_sat(Size _orig_n): orig_n(_orig_n){\n\
    \        g = Graph<bool>(orig_n * 2);  // \u9802\u70B9\u500D\u52A0\n    };\n\n\
    \    Pos toid(Pos u, bool is_u) {\n        return u * 2 + is_u;\n    }\n\n   \
    \ void add_condition(Pos u, bool is_u, Pos v, bool is_v) {\n        // add condition\
    \ (u == is_u or v == is_v)\n        g.add_edge(toid(u, is_u^1), toid(v, is_v));\n\
    \        g.add_edge(toid(v, is_v^1), toid(u, is_u));\n    }\n\n    bool build(){\n\
    \        // if successed to assigne valiables, return true, else return false\u3002\
    \n        StronglyConnectedComponents scc(g);\n        auto ts = get<1>(topological_sort(scc.dag));\n\
    \        vector<Size> ord(sz(ts));\n        rep(i, sz(ts)) ord[ts[i]] = i;\n\n\
    \        // check valid\n        rep(u, orig_n){\n            if (scc.comp[toid(u,\
    \ 0)] == scc.comp[toid(u, 1)]) {\n                return false;\n            }\n\
    \        }\n\n        assigned = vector<int>(orig_n, -1);\n        rep(u, orig_n){\n\
    \            assigned[u] = (ord[scc.comp[toid(u, 0)]] < ord[scc.comp[toid(u, 1)]]\
    \ ? 1 : 0);\n        }\n        return true;\n    }\n};\n// how to use\n// two_sat\
    \ ts(n); // n\u5909\u6570\n// ts.add_condition(x, 1, y, 0);  // represents (x==1\
    \ or y==0)\n// ......\n// ......\n// auto valid = ts.build();\n// if (valid) dump(ts.assigned);\n\
    \n//%snippet.end()%\n#line 3 \"library/cpp/graph/tests/two_sat.test.cpp\"\n\n\
    int main() {\n    int n,m;cin>>n>>m;\n    vector<int> l(n), r(n);\n    rep(i,\
    \ n){\n        cin>>l[i]>>r[i];\n    }\n\n    two_sat ts(n);\n\n    rep(i, n){\n\
    \        rep(j, i+1, n){\n            if (r[j] < l[i] || r[i] < l[j]) {\n    \
    \        }\n            else{\n                ts.add_condition(i, 0, j, 0);\n\
    \                ts.add_condition(i, 1, j, 1);\n            }\n\n            if\
    \ (r[j] < m-1-r[i] || m-1-l[i] < l[j]) {\n            }\n            else{\n \
    \               ts.add_condition(i, 0, j, 1);\n                ts.add_condition(i,\
    \ 1, j, 0);\n            }\n        }\n    }\n    auto valid = ts.build();\n \
    \   cout << (valid ? \"YES\" : \"NO\") << endl;\n\n    return 0; \n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/274\"\n#include \"../two_sat.hpp\"\
    \n\nint main() {\n    int n,m;cin>>n>>m;\n    vector<int> l(n), r(n);\n    rep(i,\
    \ n){\n        cin>>l[i]>>r[i];\n    }\n\n    two_sat ts(n);\n\n    rep(i, n){\n\
    \        rep(j, i+1, n){\n            if (r[j] < l[i] || r[i] < l[j]) {\n    \
    \        }\n            else{\n                ts.add_condition(i, 0, j, 0);\n\
    \                ts.add_condition(i, 1, j, 1);\n            }\n\n            if\
    \ (r[j] < m-1-r[i] || m-1-l[i] < l[j]) {\n            }\n            else{\n \
    \               ts.add_condition(i, 0, j, 1);\n                ts.add_condition(i,\
    \ 1, j, 0);\n            }\n        }\n    }\n    auto valid = ts.build();\n \
    \   cout << (valid ? \"YES\" : \"NO\") << endl;\n\n    return 0; \n}\n"
  dependsOn:
  - library/cpp/graph/two_sat.hpp
  - library/cpp/graph/strongly_connected_components.hpp
  - library/cpp/header.hpp
  - library/cpp/graph/graph.hpp
  - library/cpp/graph/edge.hpp
  - library/cpp/graph/tree.lib/tree.hpp
  - library/cpp/array/segtree/segment_tree.hpp
  - library/cpp/graph/unionfind.hpp
  - library/cpp/graph/topological_sort.hpp
  isVerificationFile: true
  path: library/cpp/graph/tests/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 20:20:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/cpp/graph/tests/two_sat.test.cpp
layout: document
redirect_from:
- /verify/library/cpp/graph/tests/two_sat.test.cpp
- /verify/library/cpp/graph/tests/two_sat.test.cpp.html
title: library/cpp/graph/tests/two_sat.test.cpp
---