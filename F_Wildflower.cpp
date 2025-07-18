#include<bits/stdc++.h>
using namespace std;
 
#define ll                      long long int
#define lld                     long double
//Ordered set(tree)
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
template <typename T> using order_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

vector < int > g[N];
bool vis[N];
int rt, cnt;

void dfs(int node){
    vis[node] = 1; cnt++;
    if(g[node].size() > 2 || (g[node].size() == 2 && node == 1)){
        rt = node; return;
    }
    for(auto u : g[node]){
        if(!vis[u]) dfs(u);
    }
}

int dfs2(int node){
    vis[node] = 1;
    int t = 1;
    for(auto u : g[node]){
        if(!vis[u]) t += dfs2(u);
    }
    return t;
}

void solve(){
    int n; cin >> n;
    loop(i, 1, n){
        g[i].clear(); vis[i] = 0;
    }
    loop(i, 2, n){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int c = 0;
    loop(i, 2, n){
        if(g[i].size() == 1) c++;
    }
    if(c > 2){
        cout << "0\n"; return;
    }
    if(c == 1){
        ll x = POW(2, n);
        cout << x; ed return;
    }

    cnt = 0;
    dfs(1);
    vector < int > v;
    for(int node : g[rt]){
        if(vis[node]) continue;
        v.push_back(node);
    }
    if(g[v[0]].size() == 1 && g[v[1]].size() == 1){
        ll x = POW(2, n-1);
        cout << x; ed return;
    }
    else if(g[v[0]].size() == 1 || g[v[1]].size() == 1){
        ll x = (POW(2, n-2) + POW(2, n-3)) % M;
        cout << x; ed return;
    }
    else{
        ll p = dfs2(v[0]);
        ll q = dfs2(v[1]);
        ll r = abs(p-q);
        if(r == 0){
            ll x = POW(2, cnt+1);
            cout << x; ed return;
        }
        else{
            ll x = (POW(2, cnt+r-1) + POW(2, cnt+r)) % M;
            cout << x; ed return;
        }
    }
}

int main(){
    FIO
    TC(t) 
    solve();
    return 0;
}