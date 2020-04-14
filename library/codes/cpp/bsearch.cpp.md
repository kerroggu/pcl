---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: codes/cpp/bsearch.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c19064045d3d46a80d9dc742b659ff9">codes/cpp</a>
* <a href="{{ site.github.repository_url }}/blob/master/codes/cpp/bsearch.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-26 18:44:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//%snippet.set('bsearch')%
int left = 0;
int right = 1000000001;
auto isright = [&](int x) {
  cerrendl;
  //
  bool ans = (cond ? true : false);
  dump(x, ans);
  return ans;
};
while(right-left>1){
  int mid = (right+left)/2;
  if (isright(mid)) { right = mid;}
  else{ left = mid; }
}
dump(right);

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "codes/cpp/bsearch.cpp"
//%snippet.set('bsearch')%
int left = 0;
int right = 1000000001;
auto isright = [&](int x) {
  cerrendl;
  //
  bool ans = (cond ? true : false);
  dump(x, ans);
  return ans;
};
while(right-left>1){
  int mid = (right+left)/2;
  if (isright(mid)) { right = mid;}
  else{ left = mid; }
}
dump(right);

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
