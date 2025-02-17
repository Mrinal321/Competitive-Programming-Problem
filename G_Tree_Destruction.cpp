#include<bits/stdc++.h>
using namespace std;
 
#define ll                      long long int
#define lld                     long double
//Ordered set(tree)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
//Macros
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define ini(x, y)               memset(x, y, sizeof(x))
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define pn                      cout << "NO\n";
#define py                      cout << "YES\n";
#define ed                      cout << "\n";
#define flush                   cout.flush();
#define vrev(v)                 reverse(v.begin(),v.end());
#define vsort(v)                sort(v.begin(),v.end());
#define uni(v)                  v.erase(unique(v.begin(), v.end()), v.end()); // last it is like e set
#define vlowerB(v,x)            lower_bound(v.begin(), v.end(), x); 
#define vupperB(v,x)            upper_bound(v.begin(), v.end(), x); 
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
//Constants
const ll M = 1e9 + 7;
const ll N = 2e5 + 5;
ll POW(ll a,ll b){ ll ans=1; while(b){ if(b&1) ans = (ans * a) % M; a = (a * a) % M; b >>= 1; } return ans; }
/*  Contest time:
    1. Check it is binary searce or not.
    2. DP or not.
    3. Segment Tree of not
    4. Hash or not.
    5. Number theory   
*/

vector < ll > g[N];
bool vis[N];
ll ar[N];

ll dfs(int node){
    vis[node] = 1;
    vector < ll > v;
    for(auto u : g[node]){
        if(!vis[u]) v.push_back(dfs(u));
    }
    if(v.empty()) ar[node] = 1;
    else{
        vsort(v); vrev(v);
        //cout << node << " " << v[0];ed
        if(g[node].size() < 2) ar[node] = v[0];
        else ar[node] = v[0] + g[node].size()-2;
    }

    return ar[node];
}

ll mx;
void dfs2(int node){
    vis[node] = 1;
    vector < ll > v;
    for(auto u : g[node]){
        if(!vis[u]) v.push_back(ar[u]);
    }
    if(v.size() == 1){
        ll p = v[0] + g[node].size() -1;
        mx = max(p, mx);
    }
    else if(v.size() > 1){
        vsort(v); vrev(v);
        ll p = g[node].size()-2;
        mx = max(mx, v[0]+v[1]+p);
    }
    for(auto u : g[node]){
        if(!vis[u]) dfs2(u);
    }
}

void solve(){
    ll n; cin >> n;
    loop(i, 1, n){
        g[i].clear(); vis[i] = 0; ar[i] = 0;
    }
    loop(i, 2, n){
        ll x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    loop(i, 1, n) {
        //cout << ar[i] << " "; ed
        vis[i] = 0;
    }
    mx = 0;
    dfs2(1);
    cout << mx; ed
}
 
int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}