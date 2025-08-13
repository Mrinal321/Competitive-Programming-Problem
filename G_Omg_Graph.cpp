#include<bits/stdc++.h>
using namespace std;

#define ll                      long long int
//Ordered set(tree)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
template <typename T> using order_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define loop(i, a, b)           for(int i = a; i <= b; i++)
#define loop2(i, b, a)          for(int i = b; i >= a; i--)
#define pn                      cout << "NO\n";
//#define py                      cout << "YES\n";
#define ed                      cout << "\n";
#define vrev(v)                 reverse(v.begin(),v.end());
#define vsort(v)                sort(v.begin(),v.end());
#define bits(x)                 __builtin_popcountll(x)
//Constants
const ll M = 1e10 + 7;
const ll N = 2e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

//code of Luv
ll parent[N], sz[N], mn[N], mx[N];

void make(int v){
  parent[v] = v;
  sz[v] = 1;
  mn[v] = M; mx[v] = 0;
}

ll find(int v){
  if(v == parent[v]) return v;
  return find(parent[v]);
}

void Union(int a, int b, ll maxi, ll mini){
  a = find(a);
  b = find(b);
  if(a != b){
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    mx[a] = maxi; mn[a] = mini;
  }
}


void solve(){
    int n, m; cin >> n >> m;
    loop(i, 1, n) make(i);
    vector < pair < int, pair < int, int > > > vp;
    loop(i, 1, m){
        int x, y, w; cin >> x >> y >> w;
        vp.push_back({w, {x, y}});
    }

    vsort(vp);
    ll ans = M;
    for(auto& e : vp){
        ll w = e.first;
        int x = e.second.first;
        int y = e.second.second;
        ll px = find(x), py = find(y);
        ll maxi = max({w, mx[px], mx[py]});
        ll mini = min({w, mn[px], mn[py]});
        Union(x, y, maxi, mini);
        if(find(1) == find(n)){
            ll parent1 = find(1);
            ans = min(ans, mn[parent1]+mx[parent1]);
        }
    }

    cout << ans; ed
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}